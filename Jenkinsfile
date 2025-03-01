pipeline {
    agent any
    
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Docker Build') {
            steps {
                // This builds the Docker image using your Dockerfile
                // The Dockerfile should contain all build steps including cmake
                sh 'docker build -t jeromejoseph/calculator:latest .'
            }
        }
        
        stage('Test in Container') {
            steps {
                // Run tests inside the container we just built
                sh 'docker run --rm jeromejoseph/calculator /app/build/calculator_test'
            }
        }
        
        stage('Docker Push') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'docker-credz',
                                                usernameVariable: 'DOCKER_USERNAME',
                                                passwordVariable: 'DOCKER_PASSWORD')]) {
                    sh '''
                    echo $DOCKER_PASSWORD | docker login -u $DOCKER_USERNAME --password-stdin
                    docker push jeromejoseph/calculator:latest
                    '''
                }
            }
        }
    }
    
    post {
        always {
            cleanWs()
        }
    }
}