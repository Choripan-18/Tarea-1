Integrantes:
- Jorge Gahona, rol: 202473145-9
- Matias Ibañez, rol: 202473019-3

Preguntas:

1. Según una discusión en Stack Overflow, podémoste ver que es mas conveniente representar los pixeles con unsigned char*, debido a que este tipo de variables abarca valores
entre [0,255], el cual coincide con el rango de las imágenes RGB. Además, según Microsoft la cantidad de bytes de cada tipo de dato, y podemos apreciar que un dato del tipo <unsigned char> ocupa solamente 1byte (8bits) a diferencia del int por ejemplo, el cual ocupa 4bytes (32bits).



2. Como vimos <unsigned char> ocupa 1byte o 8bits y <unsigned int> ocupa 4byte o 32bits haciendo los cálculos:
 - En unsigned char:
	- Cada pixel tendrá 3 bytes porque como se especifica tiene los 3 canales, cada uno almacenado en 1 byte.
	- Por lo que quedaríamos  NxN pixeles y cada uno con 3 bytes
	-Entonces, si ocupamos unsigned char estaríamos utilizando NxNx3 bytes de memoria.