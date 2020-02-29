"use strict"

let html = "";

people.forEach(function(p,i){
    html += `
        <tr data-id="${p.id}">
            <td>${p.id}</td>
            <td>${p.name}</td>
            <td>${p.mass}</td>
            <td>${p.hair_color}</td>
            <td>${p.eye_color}</td>
            <td>${p.birth_year}</td>
            <td>${p.gender}</td>
        </tr>
        `;
});

_.find('table tbody').innerHTML = html;

const rows = _.findAll("table.about-table tbody tr");

rows.forEach(function(row){
    let id = row.getAttribute('data-id');
    row.addEventListener('click', function(){
        location.href = `./person.html?p=${id}`;
    });
})
