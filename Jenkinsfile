pipeline {
    agent any

    environment {
        PYTHON = 'python3' // Use 'python' if Windows
    }

    stages {
        stage('Checkout Code') {
            steps {
                git url: 'https://github.com/ChandraSekharReddyIndukuri/Dev_Branch.git', branch: 'main'
            }
        }

        stage('Install Dependencies') {
            steps {
                sh '''
                    ${PYTHON} -m pip install --upgrade pip
                    ${PYTHON} -m pip install pyserial chardet
                '''
            }
        }

        stage('Run HIL Test') {
            steps {
                sh 'mkdir -p reports'
                sh "${PYTHON} hill_test.py > reports/hil_output.log"
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
            echo "✅ Build Passed"
        }
        failure {
            echo "❌ Build Failed"
        }
    }
}

