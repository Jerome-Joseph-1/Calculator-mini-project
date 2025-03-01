pipeline {
    agent any
   
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
       
        stage('Docker Build and Test') {
            steps {
                sh 'docker build -t jeromejoseph/calculator:latest .'
                sh 'docker run --rm jeromejoseph/calculator /app/build/calculator_test'
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

    stage('Deploy with Ansible') {
        steps {
            withCredentials([
                sshUserPrivateKey(credentialsId: 'ansible-ssh-key', keyFileVariable: 'ANSIBLE_SSH_KEY')
            ]) {
                sh '''
                    cp $ANSIBLE_SSH_KEY /tmp/ansible_key
                    chmod 600 /tmp/ansible_key
                    
                    ssh -i /tmp/ansible_key -o StrictHostKeyChecking=no root@192.168.2.180 "
                        cd ~/ansible && 
                        ansible-playbook deploy-calculator.yml
                    "
                    
                    # Clean up
                    rm /tmp/ansible_key
                '''
            }
        }
    }
   
    post {
        always {
            cleanWs()
        }
    }
}