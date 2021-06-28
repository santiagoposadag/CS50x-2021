function changeColor(event) {
        var triggerObj = event.srcElement;
        var color = triggerObj.innerHTML.toLowerCase()
        switch (color) {
            case 'rojo':
                color = 'rgb(234, 29, 29)';
                break;
            case 'verde':
                color = 'rgb(78, 236, 35)';
                break;
            case 'amarillo':
                color = 'rgb(236, 227, 35)';
                break;
            case 'rosado':
                color = 'rgb(240, 78, 208)';
                break;
            case 'gris':
                color = 'rgb(167,166,167)';
                break;
            case 'morado':
                color = 'rgb(183, 0, 201)';
                break;
            case 'cafe':
                color = 'rgb(173, 127, 47)';
                break;
            case 'original':
                color = 'rgb(255, 225, 181)';
                break;
        }
        document.getElementById('fondo').style.backgroundColor = color;
}

