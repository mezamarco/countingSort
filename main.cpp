#include <iostream>
#include <vector>
//#include <ctime>

//We will solve the sorting problem


//Function prototype
void printVect(std::vector<int> & vect);

int main(){




	//Create a vector with random values
	std::vector<int> myVect; 
	
	

	//Use srand(time(NULL)) in order to get true random values
	srand(time(NULL));



	std::cout << "Give me a range of value.\nStart Value: ";
	
	int startVal;
	int endVal;

	std::cin>>startVal;
	std::cout << "\nEnd Value: ";
	std::cin >>endVal;


	std::cout << "The Range is: (" <<startVal << " , " << endVal << ")\n\n";

	std::cout << "How big will the vector be: ";
	int size;
	std::cin >>size;

	std::cout <<"\n\n";
							


	int randVal;
	
	for(int i = 0; i < size; i++){
	
		randVal = (rand() % (endVal+1));
		myVect.push_back(randVal);
	}
	

	//We have populated the vector and now lets print out the vector

	printVect(myVect);




	//To solve this problem, 
	//we need to count the frquencies of the numbers 
	
	//We need to initialize a vector with zeros
	//The size of the vector will be the same the given range in the original vector
	std::vector<int> frequencyVect((endVal+1),0);


	std::cout << "\nWe have created a new vector: \n";
	printVect(frequencyVect);
	
	//We will go over the original vector and count the frequencies of the numbers.
	for(int num: myVect){
		frequencyVect[num] = frequencyVect[num] + 1;
	}


	std::cout << "\nWe have our frequency vector: \n";
	printVect(frequencyVect);

	//We need to make anoter vector with the same size as the frequency vector
	//Just copy the first val over
	std::vector<int> secVect = frequencyVect;

	//We must update this new vector and do a sum for every pair, 
	//careful with the bounds, start at index 1, 
	//update the current index with the sum of the previous and current index.
	int theSize  = secVect.size();

	for(int j = 1; j < theSize ; j++){

		secVect[j] = secVect[j-1] + secVect[j]; 
	
	}

	std::cout << "\n\n(Second Vect)";
	printVect(secVect);



	//We will now place the element in their correct positions
	std::vector<int> ansVect(myVect.size(), 0);
	//We need to use the myVect and secVect to determine the position
	//Note that the sectVect, 
	//tells us the number of element that less than or equal to current number
	//
	
	//Traverse our original array with from the end to the beggining.
	int theIndex;
	for(int m = myVect.size()-1; m >= 0; m--){
	
		//Get the element from the original vector,
		//determine its secVect value(the number that are <= to the current value).
		theIndex = secVect[ myVect[m]];
		//Reduce the count of secVect in that specific index.
		secVect[myVect[m]] -= 1;

		//Now place the element into its correct position
		//Note that we have to decrement the index pos and then place the value into
		//our ansVect
		ansVect[ theIndex -1]  = myVect[m]; 
	       		

	}

	//We have our answer vector.
	//Everything has been sorted
	//Print out the answer vector
	std::cout << "\n\nSORTED VECTOR,";
	printVect(ansVect);
	return 0;

}



void printVect(std::vector<int> & vect){


	std::cout << "\nPrinting Vector: \n";
	//Lets print our the vector
	for(int val: vect){

		std::cout << val << "  ";
		
	}

	return;
}
