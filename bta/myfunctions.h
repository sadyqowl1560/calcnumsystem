//
// Get number of digits
int gnod(long long number)
{
 int n = 0 ;
 if (number < 0)
  return 0;
 else{
  while(number > 0)
  {
   n++ ;
   number = number / 10 ;
  }
 return n ;
 }
}
//
// convert binary number to decimal
long long cbtdn(long long number , int nod /*number of degits*/)
{
// defination :
 int det_n = 0 /* determine number ex : 102 -100 = 2 */, counter = 0 ;
 long long sum = 0 , tmp_n = 0 /*temporary number for storing next loop number */, tmp_nt =0 /*temporary number two for multipication usage*/;
 
 
 while (counter < nod && number > 0)
 {
// Get each degit 
  tmp_n = number / 10 ;
  tmp_nt = tmp_n * 10 ;
  det_n = number - tmp_nt ;
// Allow 0 or 1 only
  if(det_n == 0 || det_n == 1)
  {
   sum = sum + det_n * pow(2,counter) ;
   number = tmp_n ;
   counter++;
  }else{
// Abort if input has digits not 1 and 0 
  puts("Invalid Input");
  exit(EXIT_FAILURE);
  }
}
// Return decimal number
 return sum ;
}
//
// Convert binary  to octal number
char *  cbton(long long number , int nod /*number of degits*/)
{
// defination :
 int det_n = 0 /* determine number ex : 100110 -100000 = 110 */, counter = 0 , counter_t = 0 ;
 long long sum[nod] , tmp_n = 0 /*temporary number for storing next loop number */, tmp_nt =0 /*temporary number two for multipication usage*/;
// Set all arrary elements 0
    for (counter = 0 ; counter < nod ; counter++)
         sum[counter] = 0  ;
// Calculate numbers
 counter = nod - 1 ;
 while (counter >= 0 && number > 0)
 {
// Get each 3 degit
  tmp_n = number / 1000 ;
  tmp_nt = tmp_n * 1000 ;
// Here are 3 digits
  det_n = number - tmp_nt ;
// Send to converting binary - decimal fuction 
  sum[counter] = cbtdn(det_n,gnod(det_n)) ;
// Put next number without 3 digits for next loop 
  number = tmp_n ;
  counter-- ;
 }
// Get location for non zero digits which we need ex : 000123 , get location for 123 = last three degits
 for (counter = 0 ; counter < nod ; counter++)
    {
     if (sum[counter] == 0 && counter_t == 0){
         //nothing
     }else{
        //Count digits
        counter_t++ ;
     }
    }
// Converting to string then string pointer  as C does not allow to return arrary in function    
// Plus one to put null chracter to avoid null terminator issues 
 char waset[counter_t+1] ;
 int counter_th = 0 ;
 for (counter = counter_t ; counter >= 0 ; counter--)
     {
     waset[counter_th]=sum[nod-counter] + '0';
     counter_th++ ;
     }
// Put null chracter to avoid null terminator issues 
    waset[counter_t] = '\0' ;
// Move all stuff to string pointer to return it
 char * endoftrip  ;
 endoftrip = (char*) malloc((strlen(waset))*sizeof(char));
 strcpy(endoftrip,waset) ;
 return endoftrip ;
}




//
// Convert binary number to hexadecimal
char *  cbthdn(long long number , int nod /*number of degits*/)
{
// defination :
 int det_n = 0 /* determine number ex : 1001110 -100000 = 1110 */, counter = 0 /*temporary number for storing next loop number */, counter_t = 0 /*temporary number two for multipication usage*/;
 long long sum[nod] , tmp_n = 0 /*temporary number for storing next loop number */, tmp_nt =0 /*temporary number two for multipication usage*/;
// Set all arrary elements 0
    for (counter = 0 ; counter < nod ; counter++)
         sum[counter] = 0  ;
// Calculate numbers
 counter = nod - 1 ;
 while (counter >= 0 && number > 0)
 {
// Get each 4 degit
  tmp_n = number / 10000 ;
  tmp_nt = tmp_n * 10000 ;
// Here are 4 digits
  det_n = number - tmp_nt ;
// Send to converting binary - decimal fuction 
  sum[counter] = cbtdn(det_n,gnod(det_n)) ;
// Put next number without last 4 digits for next loop 
  number = tmp_n ;
  counter-- ;
 }
// Get location for non zero digits which we need ex : 00012[10] , get location for 12[10] = last three degits
for (counter = 0 ; counter < nod ; counter++)
    {
     if (sum[counter] == 0 && counter_t == 0){
         //nothing
     }else{
        //Count digits
        counter_t++ ;
     }
    }
// Converting to string then string pointer  as We have alpabitical letters
// Plus one to put null chracter to avoid null terminator issues 
char waset[counter_t+1] ;
int counter_th = 0 ;
 for (counter = counter_t ; counter >= 0 ; counter--)
    {
// Convert each number to  its letter 
     switch(sum[nod-counter])
    {
        case 10 :
            waset[counter_th]='A';
            break;
        case 11 :
            waset[counter_th]='B';
            break;
        case 12 :
            waset[counter_th]='C';
            break;
        case 13 :
            waset[counter_th]='D';
            break;
        case 14 :
            waset[counter_th]='E';
            break;
        case 15 :
            waset[counter_th]='F';
            break;
        default:
              waset[counter_th]=sum[nod-counter] + '0';
    }
    counter_th++ ;
    }
// Put null chracter to avoid null terminator issues 
    waset[counter_t] = '\0' ;
// Move all stuff to string pointer to return it
char * endoftrip  ;
endoftrip = (char*) malloc((strlen(waset))*sizeof(char));
strcpy(endoftrip,waset) ;
return endoftrip ;
}
