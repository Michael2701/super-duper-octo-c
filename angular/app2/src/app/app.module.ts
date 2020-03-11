import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
// import { FormsModule } from '@angular/forms';
// import { ReactiveFormsModule } from '@angular/forms';
import { HttpClientModule } from '@angular/common/http';

import { CoreModule } from './core.module';
import { AuthModule } from './auth/auth.module';
import { SharedModule } from './shared/shared.module';
import { AppRoutingModule } from './app-routing.module';
import { RecipesModule } from './recipes/recipes.module';
import { ShoppingListModule } from './shopping-list/shopping-list.module';

import { AppComponent } from './app.component';
import { HeaderComponent } from './header/header.component';
import { IngredientComponent } from './ingredient/ingredient.component';


@NgModule({
  declarations: [
    AppComponent,
    HeaderComponent,
    IngredientComponent
  ],
  imports: [
    BrowserModule,
    HttpClientModule,
    
    AuthModule,
    CoreModule,
    SharedModule,
    RecipesModule,
    AppRoutingModule,
    ShoppingListModule,
  ],
  bootstrap: [AppComponent]
})
export class AppModule { }
