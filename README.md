philosophers 🧠🍝

Este proyecto es una implementación del problema clásico de los "Filósofos Comensales" utilizando hilos y mutex en C. 
La simulación presenta a varios filósofos sentados en una mesa redonda compartiendo un bol de espaguetis y tenedores. 
Cada filósofo puede comer, pensar o dormir, pero deben coordinarse para evitar conflictos por los recursos (tenedores) y garantizar que ninguno muera de inanición.

El programa acepta parámetros como el número de filósofos, tiempos límite para comer, dormir y morir,
y una opción para detener la simulación cuando los filósofos hayan comido un número definido de veces. 
Los estados de los tenedores están protegidos mediante mutex para evitar data races y garantizar un comportamiento sincronizado.
