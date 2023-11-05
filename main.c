 #include <stdio.h>
 #include <math.h>

int main() {
    
    float wageHours;                    // user entered wage hours, maximum is 168 hours per week//
    float overtimeWageHours;            // overtime hours, 
    float basicPayRate;                 // Declaration only, value to be determined in another line
    float netWages;
    float taxDeductions;                // Total tax deductions
    int hoursInDay = 24;                // 24 hours in one day.
    int workDays = 0;                   // number of work days, value to be determined in another line
    int overTimePay;
    
    //*******  Maximum number of days possible in the work week  ***////
    workDays = 7;
    
    //*****  Employee hourly wage   *****////
    basicPayRate = 12;
    
    //  Overtime wage formula  //
    overTimePay = (1.5 * basicPayRate);
    
    //  Max labor hours possible  //
    float maxPosibleHours = (workDays * hoursInDay);
    
    
    //  Promp user for hours of labor  //
    
    printf("Enter total number of hours worked this week.\n");
    
    //  Store keyboard input in wageHours  //
    scanf("%f", &wageHours);
    
    
     //  Gross wage for regular rate, (non-overtime)  //
    float grossWages = (basicPayRate * wageHours);
    
    //   Conditional statement to prevent labor hours from exceeding hours possible  // 
    
        if (wageHours > maxPosibleHours) {
        
                    printf("ERROR!\n The number of hours entered exceed the number of hours in the work week\n Try again!\n");
        
        } else {
            
                    //  Conditional to check if the pay is overtime pay or regular pay  //
                    if (wageHours <= 40) {
                                  
                                // Labor hours and gross pay  //
                                printf("Regular labor hours: %.2f.\n Overtime hours: 0 \n ", wageHours);
                                printf("Gross Pay: $%.2f\n", grossWages);
      

                                //  Conditional to tax the first 300 dollars 15 percent  //
                                if (grossWages <= 300) {
                                    
                                    taxDeductions = grossWages * 0.15; // Total tax deductions
                                    netWages = grossWages - taxDeductions;
                                    
                                    printf("Tax deductions: $%.2f\n", taxDeductions);
                                    printf("Net pay: $%.2f \n", netWages);
                                    
                                    return 0;
                                    
                                // Conditional to tax the additional 150 dollars 20 percent  //
                                }  else if (grossWages> 300 && grossWages <= 450) { 
                                    
                                            taxDeductions = (300 * 0.15) + ( (grossWages - 300) * 0.20); // Total tax dexductions
                                            netWages = grossWages - taxDeductions;
                                            
                                            printf("Tax deductions: $%.2f\n", taxDeductions);
                                            printf("Net pay: $%.2f\n", netWages);
                                            
                                            return 0;
                                    
                                } else {
                                        
                                //  Remaining to be taxed 25 Percent  // 
                                
                                        taxDeductions = (300 * 0.15) + (150 * 0.20) + ( (grossWages - 450) * 0.25 ); // Total tax deductions
                                        netWages = grossWages - taxDeductions;
                                        
                                        printf("Tax deductions: $%.2f \n", taxDeductions);
                                        printf("Net pay: $%.2f\n", netWages);
                                        
                                        return 0;
                                }    
                      
                        } else {
                            
                                /////*****   Overtime Conditional      *******///////
                            
                            // Calculate overtime hours by subtracting 40 hours from hours worked
                            overtimeWageHours = (wageHours - 40);
                            
                            //Calculate total pay including overtime pay and basic pay * 40 hours
                            grossWages = (overtimeWageHours * overTimePay) + (basicPayRate * 40);
                            
                            
                            // Labor hours and gross pay //
                            printf("Regular labor hours: 40\n Overtime labor hours: %.2f \n", overtimeWageHours );
                            printf("Gross pay:  $%.2f\n", grossWages);
                            
//                            return 0;

                                if (grossWages <= 300) {
     
                                    taxDeductions = grossWages * 0.15; // Total tax deductions
                                    netWages = grossWages - taxDeductions;
                                    
                                    printf("Tax deductions: $%.2f\n", taxDeductions); 
                                    printf("Net pay: $%.2f\n", netWages);
                                    
                                    return 0;
                                    
                                }  else if (grossWages> 300 && grossWages <= 450) { 
                                    
                                            taxDeductions = (300 * 0.15) + ((grossWages - 300) * 0.20);  // Total tax deductions
                                            netWages = grossWages - taxDeductions;
                                            
                                            printf("Tax deductions: $%.2f\n", taxDeductions);
                                            printf("Net pay $%.2f\n", netWages);
                                            
                                            return 0;
                                    
                                } else {
                                        
                                    
                                        taxDeductions = (300 * 0.15) + (150 * 0.20) + ( (grossWages - 450) * 0.25 );  // Total tax deductions
                                        netWages = grossWages - taxDeductions;
                                        
                                        
                                        printf("Tax deductions: $%.2f\n", taxDeductions);
                                        printf("Net pay:  $%.2f\n", netWages);
                                        
                                         return 0;
                                }    
                            }
                            

                        }
        
    }