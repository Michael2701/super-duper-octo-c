import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
// import { ShoppingListComponent } from './shopping-list/shopping-list.component';
import { AuthComponent } from './auth/auth.component';
// import { AuthGuard } from './auth/auth.guard.service';

const routes: Routes = [
  {path: '', pathMatch: 'full', redirectTo: 'recipes'},
  // {path: 'shopping-list', component: ShoppingListComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
