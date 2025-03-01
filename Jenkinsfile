pipeline {
    agent any
    
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        
        stage('Docker Build and Test') {
            agent {
                docker {
                    image 'docker:dind'
                    args '-v /var/run/docker.sock:/var/run/docker.sock'
                }
            }
            steps {
                sh 'docker build -t jeromejoseph/calculator:latest .'
                sh 'docker run --rm jeromejoseph/calculator /app/build/calculator_test'
            }
        }
        
        stage('Docker Push') {
            agent {
                docker {
                    image 'docker:dind'
                    args '-v /var/run/docker.sock:/var/run/docker.sock'
                }
            }
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
    
    post {
        always {
            cleanWs()
        }
    }
}