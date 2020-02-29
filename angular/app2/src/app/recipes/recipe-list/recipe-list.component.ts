import { Component, OnInit, Output, EventEmitter } from '@angular/core';
import { Recipe } from '../recipe.model';

@Component({
  selector: 'app-recipe-list',
  templateUrl: './recipe-list.component.html',
  styleUrls: ['./recipe-list.component.scss']
})
export class RecipeListComponent implements OnInit {
  recipes: Recipe[] = [
    new Recipe('A Test Recipe 1', 'This is simply a test', 'https://barbecuebible.com/wp-content/uploads/2019/09/featured-baby-back-ribs-with-guava-barbecue-sauce-1024x640.jpg'),
    new Recipe('A Test Recipe 2', 'This is simply a test', 'https://barbecuebible.com/wp-content/uploads/2019/09/featured-baby-back-ribs-with-guava-barbecue-sauce-1024x640.jpg')
  ];
  
  @Output() recipeSelected = new EventEmitter<Recipe>();

  constructor() { }

  ngOnInit(): void {
  }

  onRecipeSelected(selectedRecipe: Recipe){
    this.recipeSelected.emit(selectedRecipe);
  }

}
