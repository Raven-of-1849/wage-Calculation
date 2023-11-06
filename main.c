 #include <stdio.h>
 #include <math.h>
 
 //User defined constants //
 
 #define PAYRATE      12.00 // Employee hourly rate
 #define WORKDAYS     7  //  Maximum workdays possible
 #define TAXRATE_300  0.15 // First 300 tax rate
 #define TAXRATE_150  0.20 // The next 150 tax rate
 #define TAXRATE_REST 0.25 // Anything above the first two tax rates, 450 or more.

 

int main() {
    
    float wageHours;                    // user entered wage hours, maximum is 168 hours per week//
    float overtimeWageHours;            // overtime hours, 
    float netWages;
    float taxDeductions;                // Total tax deductions
    int hoursInDay = 24;                // 24 hours in one day.
    int overTimePay;
    
    //  Overtime wage formula  //
    overTimePay = (1.5 * PAYRATE);
    
    //  Max labor hours possible  //
    float maxPosibleHours = (WORKDAYS * hoursInDay);
    
    
    //  Promp user for hours of labor  //
    
    printf("Enter total number of hours worked this week.\n");
    
    //  Store keyboard input in wageHours  //
    scanf("%f", &wageHours);
    
    
    //   Conditional statement to prevent labor hours from exceeding hours possible  // 
    
        if (wageHours > maxPosibleHours) {
        
                    printf("ERROR!\n The number of hours entered exceed the number of hours in the work week\n Try again!\n");
        
        } else {
            
                    float grossWages;
            
                    //  Conditional to check if the pay is overtime pay or regular pay  //
                    if (wageHours <= 40) {
                                  
                                grossWages = (PAYRATE * wageHours); // Regular pay formula
                                
                                // Labor hours and gross pay  //
                                printf("Regular labor hours: %.2f.\n Overtime hours: 0 \n ", wageHours);
                                printf("Gross Pay: $%.2f\n", grossWages);
      

                    } else {
                            
                                /////*****   Overtime Conditional      *******///////
                            
                            // Calculate overtime hours by subtracting 40 hours from total hours worked
                            overtimeWageHours = (wageHours - 40);
                            
                            //Calculate total pay including overtime pay and basic pay * 40 hours
                            grossWages = (overtimeWageHours * overTimePay) + (PAYRATE * 40);
                            
                            
                            // Labor hours and gross pay //
                            printf("Regular labor hours: 40\n Overtime labor hours: %.2f \n", overtimeWageHours );
                            printf("Gross pay:  $%.2f\n", grossWages);

                            } 
                            
                            
                            //*****   Tax conditional      ******//
                            if (grossWages <= 300) {
     
                                    taxDeductions = grossWages * TAXRATE_300; // Total tax deductions
                           
                            }  else if (grossWages> 300 && grossWages <= 450) { 
                                    
                                    taxDeductions = (300 * 0.15) + ((grossWages - 300) * TAXRATE_150);  // Total tax deductions
                                    
                            } else {
                                        
                                    taxDeductions = (300 * 0.15) + (150 * 0.20) + ( (grossWages - 450) * TAXRATE_REST );  // Total tax deductions
                                        
                                }  

                        netWages = grossWages - taxDeductions; // Wage after taxes
                        
                        printf("Tax deductions: $%.2f\n", taxDeductions); // Print tax deductions //
                        printf("Net pay:  $%.2f\n", netWages); // Print Net pay //
                        
                        }
                        
                        return 0;
        
    }