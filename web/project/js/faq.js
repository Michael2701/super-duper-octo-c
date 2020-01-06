'use strict';

const btns = _.findAll('.accordion-btn');
const conts = _.findAll('.accordion-content');
for(let i = 0; i < btns.length; i++){
    btns[i].addEventListener('click', function(e){
        const trg = e.target.nextElementSibling;

        if(trg.classList.contains('open')){
            trg.classList.remove('open');
        }else{
            for(let j = 0; j < conts.length; j++){
                if(conts[j].classList.contains('open')){
                    conts[j].classList.remove('open')
                }
            }
            trg.classList.add('open');
        }
    });
}