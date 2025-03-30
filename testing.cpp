#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

// Importacion de librerias. Los archivos correspondientes deben estar en el mismo directorio que el .cpp.
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>

using namespace std;

// Struct que almacena la data de una imagen
struct Imagen{
    unsigned char* data;
    int width, height, channels;
};

// Abrir imagen desde memoria local
Imagen* load(const char* filename) {
    Imagen* img = new Imagen();
    img->data = stbi_load(filename, &img->width, &img->height, &img->channels, 0);
    return img;
}

// Guardar imagen en memoria local
void save(Imagen* img, const char* filename) {
    stbi_write_png(filename, img->width, img->height, img->channels, img->data, img->width * img->channels);
    cout << "Imagen guardada:  " << filename << "\n";
}

//Operacion 1
void operacion_1(Imagen* img){
// Reflexion horizontal de la imagen
    for(int i = 0; i < img->height; i++){    //Recorre las filas
        for(int j = 0; j < img->width/2; j++){ //Recorre las columnas hasta la mitad
            for(int k = 0; k < img->channels; k++){ //Recorre los canales
                int pos1 = (i * img->width + j) * img->channels + k; //Posicion actual
                int pos2 = (i * img->width + img->width - j - 1) * img->channels + k; //Posicion simetrica
                unsigned char temp = img->data[pos1]; //Guarda el valor actual
                img->data[pos1] = img->data[pos2]; //Cambia el valor actual por el simetrico
                img->data[pos2] = temp; //Cambia el valor simetrico por el actual
            }     
        }
    }
}

//Operacion 2
void operacion_2(Imagen* img){
    // Rotacion de 90 grados de la imagen
    Imagen* img_rot = new Imagen(); // Crear nueva imagen
    // Asignamos dimensiones a la nueva imagen
    img_rot->width = img->height;
    img_rot->height = img->width;
    img_rot->channels = img->channels;
    img_rot->data = new unsigned char[img_rot->width*img_rot->height*img_rot->channels];

    for(int i=0; i < img->height; i++){   //Recorre las filas
        for(int j=0; j < img->width; j++){ //Recorre las columnas
            for(int k=0; k < img->channels; k++){ //Recorre los canales

                // Asignamos la posicion de la nueva imagen
                int indice1 = (i * img->width + j) * img->channels + k; //Posicion actual
                int indice2 = (j * img_rot->width + (img->height - 1 - i)) * img_rot->channels + k; //Posicion rotada 90°
                img_rot->data[indice2] = img->data[indice1]; //Rotacion           
            }
        }
    }
    delete[] img->data;
    //Actualizamos los datos de la imagen original con los de la rotada
    img->data = img_rot->data;
    img->height = img_rot->height;
    img->width = img_rot->width;
    img->channels = img_rot->channels;
    delete img_rot;
    
}

//operacion 3

void operacion_3(Imagen* img, float atenuacion) {
    // Atenuación de la imagen
    for (int i = 0; i < img->width * img->height * img->channels; i++) { //recorre todos los pixeles
        img->data[i] = static_cast<unsigned char>(img->data[i] * atenuacion); //multiplica el valor del pixel por la atenuacion
    }
}


// Operación 4
void operacion_4(Imagen* img, int umbral) {
    //cambio a blanco y negro
    for (int i = 0; i < img->width * img->height; i++) { // Recorre cada píxel
        int canal = i * img->channels; // busca los canales correspondientes al pixel
        unsigned char r = img->data[canal];     // Canal rojo
        unsigned char g = img->data[canal + 1]; // Canal verde
        unsigned char b = img->data[canal + 2]; // Canal azul

        // Calcular iluminacion del pixel
        unsigned char iluminacion = static_cast<unsigned char>(0.3 * r + 0.59 * g + 0.11 * b);

        // Comparar la luminancia con el umbral
        unsigned char cambio = (iluminacion > umbral) ? 255 : 0;  // condicion? si cumple : si no cumple

        // cambiar todos los canales segun corresponda
        img->data[canal] = cambio;     // Canal rojo
        img->data[canal + 1] = cambio; // Canal verde
        img->data[canal+ 2] = cambio; // Canal azul
    }
}


int main() {

    Imagen* img = load("Pikachu.png");
    operacion_1(img);
    save(img, "output.png");
    delete[] img->data;
    delete img;

    Imagen* img2 = load("Pikachu.png");
    operacion_2(img2);
    save(img2, "output_rot.png");
    delete[] img2->data;
    delete img2;

    Imagen* img3 = load("Pikachu.png");
    operacion_3(img3, 0.6);
    save(img3, "pikachu atenuado.png");
    delete[] img3->data;
    delete img3;

    Imagen* img4 = load("Pikachu.png");
    operacion_4(img4, 150);
    save(img4, "pikachu byn.png");
    delete[] img4->data;
    delete img4;


    return 0;

}
