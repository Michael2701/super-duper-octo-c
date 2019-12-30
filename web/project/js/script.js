'use strict';
// helper functions
function log(){
    for(let i = 0; i < arguments.length; i++){
        console.log(arguments[i]);
    }
}
class myClass{
    find(selector){
        return document.querySelector(selector);
    }
    findAll(selector){
        return document.querySelectorAll(selector);
    }
}
const _ = new myClass();
// end helper functions




// side menu
    const menu_btn = _.find('.hamburger');
    const side_menu = _.find('nav');
    menu_btn.addEventListener('click', function(e){
        if(side_menu.classList.contains('open')){
            side_menu.classList.remove('open');
        }else{
            side_menu.classList.add('open');
        }
    });

// end side menu



