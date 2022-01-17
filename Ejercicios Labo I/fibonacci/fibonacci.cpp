int fibonacci(int n){ 

        int actual = 0;
        if(n==0){
            // actual = 0;
        }
        else{
            if(n==1){
              actual=1;
            }
            else{
               int anteriorDelAnterior=0;
               int anterior=1;
               while (n>=2){
                   actual = anterior + anteriorDelAnterior;
                   anteriorDelAnterior = anterior;
                   anterior = actual;
                   n--;
               }
            }
        }
        
        return actual;
    }