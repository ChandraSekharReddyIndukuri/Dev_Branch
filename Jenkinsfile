pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                echo 'Checking out the repository...'
                git 'https://github.com/ChandraSekharReddyIndukuri/Dev_Branch.git'
            }
        }
        
        stage('Print Hello') {
            steps {
                echo 'Hello, Jenkins! This is a print statement.'
            }
        }
        
        stage('Run Python Script') {
            steps {
                echo 'Running Python script...'
                // Assuming the Python script is named script.py
                sh 'python script.py'
            }
        }

        stage('Print End') {
            steps {
                echo 'Jenkins pipeline execution completed!'
            }
        }
    }
}
