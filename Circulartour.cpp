class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n){
        int sumgas=0, sumcost=0;
        for(int i=0; i<n; i++){
            sumgas+= p[i].petrol;
            sumcost+= p[i].distance;
        }
        if(sumcost>sumgas) return -1;
        
        int currentGas = 0;
        int startingIndex = 0;

        for (int i = 0; i < n; i++) {
            currentGas += p[i].petrol - p[i].distance;
            if (currentGas < 0) {
                currentGas = 0;
                startingIndex = i + 1;
            }
        }
        return startingIndex;
    }
};