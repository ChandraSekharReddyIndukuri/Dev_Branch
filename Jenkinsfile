pipeline {
    agent any

    environment {
        PYTHON = 'python' // Or full path like 'C:\\Python39\\python.exe' if needed
    }

    stages {
        stage('Checkout Code') {
            steps {
                git url: 'https://github.com/ChandraSekharReddyIndukuri/Dev_Branch.git', branch: 'main'
            }
        }

        stage('Install Dependencies') {
            steps {
                bat """
                    ${PYTHON} -m pip install --upgrade pip
                    ${PYTHON} -m pip install pyserial chardet
                """
            }
        }

        stage('Run HIL Test') {
            steps {
                bat """
                    mkdir reports
                    ${PYTHON} hill_test.py > reports\\hil_output.log
                """
            }
        }

        stage('Archive Results') {
            steps {
                archiveArtifacts artifacts: 'reports/**', fingerprint: true
            }
        }
    }

    post {
        success {
            echo "✅ HIL Test Passed!"
        }
        failure {
            echo "❌ HIL Test Failed."
        }
    }
}
