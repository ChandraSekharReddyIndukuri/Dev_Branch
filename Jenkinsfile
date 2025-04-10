pipeline {
    agent any

    stages {
        stage('Checkout Code') {
            steps {
                // Clone the repository from GitHub
                git branch: 'Dev_Branch', url: 'https://github.com/ChandraSekharReddyIndukuri/Dev_Branch'
            }
        }

        stage('Prepare Environment') {
            steps {
                // Set up your environment if needed
                echo 'Preparing HIL testing environment...'
                bat '''
                echo Setting up dependencies on Windows...
                '''
            }
        }

        stage('Run HIL Test Cases') {
            steps {
                // Run your HIL test cases
                echo 'Executing HIL test script...'
                bat 'python C:\\Users\\LENOVO\\Downloads\\hill_test.py'
            }
        }

        stage('Post-Test Actions') {
            steps {
                // Collect logs and save results
                echo 'Collecting test results...'
                bat '''
                mkdir test_results
                echo Simulating result collection on Windows...
                '''
                archiveArtifacts artifacts: 'test_results\\*.log', allowEmptyArchive: true
            }
        }
    }

    triggers {
        // Trigger the pipeline on GitHub push events
        githubPush()
    }
}
