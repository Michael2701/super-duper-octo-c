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
    const menu_btn  = _.find('.hamburger');
    const side_menu = _.find('nav');
    const backdrop  = _.find('#backdrop');
    const body      = _.find('body');

    menu_btn.addEventListener('click', function(e){
        if(side_menu.classList.contains('open')){
            side_menu.classList.remove('open');
            backdrop.classList.remove('show');
            body.style.overflowY = 'scroll';
        }else{
            side_menu.classList.add('open');
            backdrop.classList.add('show');
            body.style.overflow = 'hidden';
        }
    });
    backdrop.addEventListener('click',function(e){
        side_menu.classList.remove('open');
        backdrop.classList.remove('show');
        body.style.overflowY = 'scroll';
    });

// end side menu



