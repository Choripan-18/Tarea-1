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
void reflexion(Imagen* img){
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
void rotacion(Imagen* img){
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




int main() {

    Imagen* img = load("pikachu.png");
    reflexion(img);
    save(img, "output.png");
    delete[] img->data;
    delete img;

    Imagen* img2 = load("pikachu.png");
    rotacion(img2);
    save(img2, "output_rot.png");
    delete[] img2->data;
    delete img2;

 
    return 0;


}
