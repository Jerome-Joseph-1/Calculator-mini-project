pipeline {
    agent any
    
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Build') {
            steps {
                sh '''
                mkdir -p build
                cd build
                cmake ..
                make
                '''
            }
        }
        
        stage('Test') {
            steps {
                sh '''
                cd build
                ./calculator_test
                '''
            }
        }
        
        stage('Docker Build') {
            steps {
                sh 'docker build -t jeromejoseph/calculator:latest .'
            }
        }
        
        stage('Docker Push') {
            steps {
                withCredentials([usernamePassword(credentialsId: 'docker-hub-credentials', 
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
}