'use strict';

const urlParams = new URLSearchParams(window.location.search);
const id = urlParams.get('p');

let person;
people.forEach(function(p){
    if(p.id == id){
        person = p;
    }
});

if(typeof person !== 'undefined')
{
    _.find('.slider-img img').setAttribute('src', `../img/${person.image}`);
    _.find('#hero-name').innerText = person.name;
    
    _.find('.first-col li:first-child').innerText = 'Height: '+person.height;
    _.find('.first-col li:nth-child(2)').innerText = 'Hair color: '+person.hair_color;
    _.find('.first-col li:nth-child(3)').innerText = 'Eye color: '+person.eye_color;
    _.find('.first-col li:nth-child(4)').innerText = 'Gender: '+person.gender;

    _.find('.second-col li:first-child').innerText = 'Mass: '+person.mass;
    _.find('.second-col li:nth-child(2)').innerText = 'Skin color: '+person.skin_color;
    _.find('.second-col li:nth-child(3)').innerText = 'Birth year: '+person.birth_year;

    _.find('#about').innerText = person.about;
}else{
    history.back();
}







