# Proyecto Abridor de Puerta por Wifi + MQTT

El proyecto Abridor de puerta por Wifi + MQTT utiliza un uC esp-01 con módulo wifi incluido. Este posee un cliente MQTT que se comunica de forma bidireccional con un brocker MQTT alojado en un servidor en Amazon AWS. El servidor AWS presta servicio para otros usuarios al rededor del mundo y permite escribir y leer el estado del uC esp-01. En particular, mediante una aplicación tipo "dashboard MQTT" es posible controlar la apertura y cierre de una puerta mediante un cualquier celular ubicado en cualquier parte del mundo con conexión a internet. 

# Organización de Archivos.

En la carpeta Documents, se encuentra información obsoleta del código anterior basada en otro uC (de Microchip). Por otra parte, en la carpeta src, se encuentra el sketch inicial y funcional del código abridor de puerta.

# Programas utilizados
El entorno de programación utilizado fue plataformIO basado en la IDE Atom desarrollada en GitHUb. Para la programación del uC ESP-01, se utilizó la tarjeta de adapatación usb a serial diseña para el uC ESP-01. Fue necesario realizar una adaptación en el adaptador para que funcionara. La adaptación consiste en conectar el pin GPIO0 a tierra. Esto se realizó soldando un cable directamente en la tarjeta de adaptación. 




