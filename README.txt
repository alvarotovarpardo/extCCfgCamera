#extendedConfigCamera

Este repositorio tiene como objeto la *creación automática de un archivo .h unificado*, extCfgCam.h. que contenga todos las propiedades y métodos de las clases CCfgCamGeneral de RL Fix, Distributed, Analytics & Lite, sin repetirse. 

Para ello *se debe proporcionar*:
 - Una carpeta 'private/private_raw' con las propiedades copiadas y pegadas en los ficheros private_x.txt, con x = fix, distributed, analytics, lite. 
 - Una carpeta 'public/public_raw' con los métodos copiados y pegados en los ficheros public_x.txt, con x = fix, distributed, analytics, lite. 

La *ejecución de main.py se debe hacer desde la carpeta ../extendedConfigCamera*. En esta misma ruta se creará un header extCfgCam.h, con la clase extendedCCfgCamGeneral.
En main.py se especifica si se quiere borrar la carpeta build. El resto de inputs en las funciones no deberían ser modificadas. 

En la carpeta 'private/build', se genera:
	- private_clean, conteniendo 4 .txts con las propiedades de cada clase eliminando comentarios, eliminando multidefiniciones en una línea, y la variable acompañada del tipo de dato
	- private_reduced, conteniendo 4.txt con las propiedades de cada clase eliminando comentarios, eliminando multidefiniciones en una línea, eliminando el tipo de dato y eliminando el prefijo de la variable (m_i, m_b, m_us, ...)
	- private_ordered, ordenando alfabéticamente private_clean o private_reduced, según el uso.
		De esta carpeta se generará all_private.txt, conteniendo todas las propiedades en un solo .txt, sin repetirse y ordenadas por orden alfabético.
		De all_private.txt se generará all_private_SWs.xlsx para comprobar visualmente la existencia de una propiedad en uno o varios SWs
	- private_classified, con varios archivos .txt especificando las propiedades de cada SW o conjunto de SW
		El header extCfgCamera.h se creará a partir de la lectura de private_classified. 
	
Dependiendo de si queremos el Excel y/o el header acompañando el tipo de dato, se deberá usar private_clean o private_reduced en cada caso.
Si False en 'tableAttributes(source, False)', 'masterAttributes(source, False)', se cogerá private_clean, con el tipo de dato. 


En public se hace la gestión de métodos de las clases en los cuatro softwares y se unifica todo en un solo archivo .h
