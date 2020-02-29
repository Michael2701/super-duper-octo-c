"use strict";
// image galery
const slides = [
    "30116.jpg",
    "30117.jpg",
    "30120.jpg",
    "30125.jpg",
    "30135.jpg",
    "30136.jpg",
    "30139.jpg",
    "30144.jpg",
    "30151.jpg",
    "30153.jpg"
];
const slider_img = _.find('.slider-container>.slider-img>img');
let i = 1;
const leng = slides.length;
setInterval(function(){
    if(i >= leng) i = 0;

    slider_img.classList.add('hide');
    setTimeout(function(){
        slider_img.setAttribute('src', `./img/${slides[i]}`);
    },300);
    setTimeout(function(){
        slider_img.classList.remove('hide');
        i++;
    },350);

},10000);
//end image gallery

// card
let html = "";
const cards_cont = _.find('.cards-container');
people.forEach(function(hb){
    html += `
        <div class="card">
            <div class="card-description">
                <ul class="card-text">
                    <li>Name: ${hb.name}</li>
                    <li>Height:${hb.height}</li>
                    <li>Mass: ${hb.mass}</li>
                    <li>Birth year: ${hb.birth_year}</li>
                    <li><a href="./pages/person.html?p=${hb.id}">More...</a></li>
                </ul>
            </div>
            <figure class="card-img">
                <img src="./img/${hb.image}" alt="">
            </figure>
        </div>
    `;
});
cards_cont.innerHTML = html;
// end card