import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { ParentComponent } from './parent/parent.component';
import { Tab1Component } from './tab1/tab1.component';
import { Tab2Component } from './tab2/tab2.component';
import { AppComponent } from './app.component';
import { AuthGuard } from './auth-guard.service';


const routes: Routes = [
  {path: 'parent', component: ParentComponent, children: [
      {path: 'tab1', component: Tab1Component},
      {path: 'tab2', canActivate: [AuthGuard], component: Tab2Component}
  ]}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
