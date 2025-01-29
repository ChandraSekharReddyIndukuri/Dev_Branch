pipeline {
    agent any
    stages {
        stage('Clone Repository') {
            steps {
                //git branch: 'main', git 'https://github.com/ChandraSekharReddyIndukuri/Dev_Branch.git'
                git branch: 'main', credentialsId: 'ChandraSekharReddyIndukuri', url: 'https://github.com/ChandraSekharReddyIndukuri/Dev_Branch.git'
            }
        }
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
                sh 'build.py'
            }
        }

        stage('Print End') {
            steps {
                echo 'Jenkins pipeline execution completed!'
            }
        }
   stage('Build') {
            steps {
                echo "Building the project..."
                // Add your build commands, e.g., make, mvn, or npm
            }
        }

        stage('Test') {
            steps {
                echo "Running tests..."
                // Add test commands, e.g., pytest, JUnit, etc.
            }
        }

        stage('Deploy') {
            steps {
                echo "Deploying the application..."
                // Add deployment commands, e.g., SSH to server, copy artifacts, restart service
                //testing
            }
        }
    }
}
    
        

