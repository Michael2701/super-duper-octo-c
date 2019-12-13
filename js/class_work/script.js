'use strict';
function randColor()
{
    var one =  Math.ceil(Math.random()*(255));
    var two =  Math.ceil(Math.random()*(255));
    var tree =  Math.ceil(Math.random()*(255));
    return  `rgb(${one}, ${two}, ${tree})`;    
} 

function animateText(selector, timeout)
{
    var element = document.querySelector(selector);
    var htext = element.innerText;
    var text = htext;
    var lng = text.length;
    var index = 0;
    
    setInterval( function()
    {
        if(index == lng) index = 0;
        element.innerText = text.substr(0, index);
        element.style.color = randColor();
        index++;
    },timeout);
}

animateText('#heading', 250);
animateText('#txt', 250);
animateText('#par', 300);



















