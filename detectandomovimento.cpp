
/*
#include <opencv\cv.h>
#include <opencv\highgui.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

//valor de sensibilidade usado pelos absdiff()
const static int SENSITIVITY_VALUE = 20;
//valor do blur usado para suavizar a imagem de saida  pra facilitar o absdiff
const static int BLUR_SIZE = 10;//3...9...
//buscando apenas um objeto.
//e rastrear sua posição
int theObject[2] = {0,0};
//retangulo do objeto rastreado, vamos usar a posição central dele
Rect objectBoundingRectangle = Rect(0,0,0,0);


//int para string
string intToString(int number){
    std::stringstream ss;
    ss << number;
    return ss.str();
}

void searchForMovement(Mat thresholdImage, Mat &cameraFeed){

     // usando o operador '&' para pegar a referência de objectDetected e cameraFeed,
     //pois quero manipular eles aqui, e não só copiar, eu quero desenhar na camera para exibir na main

    bool objectDetected = false;
    Mat temp;
    thresholdImage.copyTo(temp);
    // estes dois vetores são necessários para encontrar as saídas dos contornos
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    //pega os contornos dos objetos filtrados
    //findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE );// pega todos os contornos
    findContours(temp,contours,hierarchy,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_SIMPLE );// pega os contornos externos
    //se os vetores de contornos não tiverem vazios, encontramos alguns objetos
    if(contours.size()>0)objectDetected=true;
    else objectDetected = false;

    if(objectDetected){
        //o maior contorno é contrado no final do vetor de contornos
        //assumindo que o objeto com maior contorno é o que estamos procurando
        vector< vector<Point> > largestContourVec;
        largestContourVec.push_back(contours.at(contours.size()-1));
        //cria um retangulo ao redor do maior contorno e encontra o centro
        //este será o objeto da estimativa final
        objectBoundingRectangle = boundingRect(largestContourVec.at(0));
        int xpos = objectBoundingRectangle.x+objectBoundingRectangle.width/2;
        int ypos = objectBoundingRectangle.y+objectBoundingRectangle.height/2;

        //atualizando as posições do objetos pela mudança dos valores.
        theObject[0] = xpos , theObject[1] = ypos;
    }
    //criando variaveis temporarias
    int x = theObject[0];
    int y = theObject[1];

    //draw some crosshairs around the object
    circle(cameraFeed,Point(x,y),20,Scalar(0,255,0),2);
    line(cameraFeed,Point(x,y),Point(x,y-25),Scalar(0,255,0),2);
    line(cameraFeed,Point(x,y),Point(x,y+25),Scalar(0,255,0),2);
    line(cameraFeed,Point(x,y),Point(x-25,y),Scalar(0,255,0),2);
    line(cameraFeed,Point(x,y),Point(x+25,y),Scalar(0,255,0),2);

    //escreve a posição do objeto na tela
    putText(cameraFeed,"rastreando objeto em (" + intToString(x)+","+intToString(y)+")",Point(x,y),1,1,Scalar(255,0,0),2);



}
*/
/*
int main(int, char**)
{
    VideoCapture capUm(0);
    capUm.set(CV_CAP_PROP_FRAME_WIDTH,320);//640,800,1024
    capUm.set(CV_CAP_PROP_FRAME_HEIGHT,240);//480,600,768
    capUm.set(CV_CAP_PROP_FPS,15);
    if(!capUm.isOpened())  // vê se deu certo
        return -1;
    // se quer ativar debug e rastreamento
    bool debugMode = true;
    bool firstThreshold = true;
    bool secondThreshold = true;
    bool trackingEnabled = true;

    Mat frame1,frame2;
    // frames em escala de cinza para usar absdiff()
    Mat grayImage1,grayImage2;
    //imagem resultande do absdifff
    Mat differenceImage;
    // imagem depois do threshold para usar o findContours()
    Mat thresholdImage;
    while(1){
            //lê primeiro frame
            capUm >> frame1;
            //convertendo para escala de cinza
            cvtColor(frame1,grayImage1,COLOR_BGR2GRAY);
            //copia segundo frame
            capUm >> frame2;
            cvtColor(frame2,grayImage2,COLOR_BGR2GRAY);

             //faz o diferenciamento das imagens, que resulta numa imagem de intencidade,
            // ainda vai precisar do threshold

            absdiff(grayImage1,grayImage2,differenceImage);

            //threshold imagem dado um valor de sensibilidade
            threshold(differenceImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);

            //ERRO ESTÁ AQUI EMBAIXO
            if(debugMode==true){
                if(differenceImage.empty()==0) {
                    imshow("Difference Image",differenceImage);
                        if(waitKey(30) >= 0)
                            break;
                }
                if(thresholdImage.empty()==0 && firstThreshold == true) {
                    imshow("Threshold Image", thresholdImage);
                        if(waitKey(30) >= 0)
                            break;
                }
            }

            //fazendo blur para para remover ruido
            blur(thresholdImage,thresholdImage,Size(BLUR_SIZE,BLUR_SIZE));
            //segundo threshold para pegar uma imagem binária feita com a saída do blur
            threshold(thresholdImage,thresholdImage,SENSITIVITY_VALUE,255,THRESH_BINARY);
            //exibindo imagem com threshold
            if(debugMode == true && secondThreshold == true){
                if(thresholdImage.empty()==0) {
                    imshow("final threshold image", thresholdImage);
                        if(waitKey(30) >= 0)
                            break;
                }
            }
            //se o rastreamento está ativado, enviar para função de buscar contornos
            if(trackingEnabled){
                searchForMovement(thresholdImage,frame1);
            }

            ///////////////////////////////////////////////////

            //exibição da câmera
            if(frame1.empty()==0) {
                imshow("Frame1", frame1);
                    if(waitKey(30) >= 0)
                        break;
            }
    }

    return 0;

}
*/
