Integrantes:
- Jorge Gahona, rol: 202473145-9
- Matias Ibañez, rol: 202473019-3

Preguntas:

1. Según una discusión en Stack Overflow, podémos ver que es mas conveniente representar los pixeles con unsigned char*, 
	debido a que este tipo de variables abarca valores entre [0,255], el cual coincide con el rango de las imágenes RGB. 
	Además un dato del tipo <unsigned char> ocupa solamente 1byte (8bits) a diferencia del int por ejemplo, el cual ocupa 4bytes (32bits).



2. Como vimos <unsigned char> ocupa 1byte o 8bits y <unsigned int> ocupa 4byte o 32bits haciendo los cálculos:
 - En unsigned char:
	- Cada pixel tendrá 3 bytes porque como se especifica tiene los 3 canales, cada uno almacenado en 1 byte.
	- Por lo que quedaríamos  NxN pixeles y cada uno con 3 bytes
	-Entonces, si ocupamos unsigned char estaríamos utilizando NxNx3 bytes de memoria.

- Con unsigned int:
	- Cada pixel tendra 3 canales y cada uno ocupara 4 bytes.
	- Entonces, estariamos utilizando NxNx3x4 bytes de memoria

- En conclusion ocupar unsigned char conviene mas porque para este caso ocupa menos memoria

3. si consideramos la primera fila y primera columna como posicion 0, entonces podemos ver 0 + 0 + 2 (2 seria la
	la posicion del canal azul considerando 0 como el rojo) Por lo tanto la posicion seria 2.

4. ¿Como podemos convertir una imagen RGB a escala de grises?
	Podemos utilizar el promedio ponderado de iluminancia dandole mas peso al verde, luego al rojo y finalmente al azul.
	Siguiendo esta formula: Gris = 0.299 * R + 0.587 * G + 0.114 * B

Fuentes:

	1, 2, y 3. Usuario: nkint. (21/04/2011) why unsigned char for RGB pixel data?.
				Recuperado de: https://stackoverflow.com/questions/5742967/why-unsigned-char-for-rgb-pixel-data?utm_source=chatgpt.com

	4. Vision y Robotica. (11/03/2021). Cómo convertir imagen RGB a escala de grises (GUÍA COMPLETA!!! 🔥)
		Recuperado de https://www.youtube.com/watch?v=qPclS-zV458

Pregunta 6: El error puede ser, por experiencia, que la condición (si la iluminación del píxel es mayor o menor que el umbral dado como parámetro
a la función) se evalúa para cada canal del píxel por separado, en vez de tomar los 3 canales en conjunto para calcular la iluminación del píxel
usando la fórmula estándar y luego reemplazando los 3 canales por el mismo valor (0 o 255).