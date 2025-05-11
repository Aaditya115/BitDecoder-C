/*BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE TENURES
OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO THIS
ASSIGNMENT.
*/

// Author: Aaditya Gupta

#include <stdio.h> 
#define MAX_CHAR  200 

/*In this lab I am creating a text decrypter. So the user will enter the 4 bit key that was used to encrypt the text, aswell as the encrypted text. My job is to use that 4 bit key to output the decrypted text message.
*/


//Prototype functions
unsigned char create_key();
void decrypt(unsigned char key);
unsigned char rotate_right(unsigned char byte);
unsigned char rotate_left(unsigned char byte);

//Main method, this method is responsible for calling the other methods in this file.
int main(){
	unsigned char key;
#ifdef PROMPT
	printf("Please enter 4-bit key: ");
#endif
       key = create_key();
#ifdef PROMPT
       printf("Please enter encrypted text: ");
#endif
       decrypt(key);
      

	return 0;
}


//The create_key method is responsible for retriving the user's 4-bit key, and creating an 8-bit key which is the double of the 4-bit key.
unsigned char create_key(){
	
	unsigned char key =0;
	char digit=0;
	for(int i=0; i<4; i++){
		digit = getchar(); //Utilizing the getchar() function to be able to process each bit one at a time.

		if(digit == '0'){ 
			digit =0; // Converting char values to integer. 
		}else if(digit == '1'){
			digit = 1;
		}
		key = (key << 1) | digit; //As the loop iterates, key will shift left and do a bitwise OR with the digit. When the loop terminates, key's last 4 bits will be the key and the rest will be 0.
	}
	key = (key << 4) | key; //This shift the 4-bit key to front, and then do a bitwise or with key. 
       
	return key;
}

//The rotate_right method is responsible for rotating the encrypted text 1 bit to the right.		    
unsigned char rotate_right(unsigned char byte){
	unsigned char right = byte >> 1;
	unsigned char left = byte << 7;
	unsigned char right_rotate = right | left;
	return right_rotate;
}
//The rotate left method is responsible for rotating the encrypted text 1 bit to the left.
unsigned char rotate_left(unsigned char byte){
	unsigned char left = byte << 1;
	unsigned char right = byte >> 7;
	unsigned char left_rotate = left | right;
	return left_rotate;
}
//The decrypt method is responsible for retrevivng the user's decrypted text, calling the rotate method to decrypt the text, and outputing the the decrypted text.
void decrypt(unsigned char key){
	unsigned char encrypted_txt;
       	unsigned int text_count =0;
	unsigned char decrypted_txt;	
	while(scanf("%2hhx", &encrypted_txt) ==1 && text_count <= MAX_CHAR){
		if(text_count %2 ==0){
			encrypted_txt = rotate_right(encrypted_txt);
		}else{
			encrypted_txt = rotate_left(encrypted_txt);
		}

		decrypted_txt = encrypted_txt ^key;
		putchar(decrypted_txt);
		text_count++;
	
		if(getchar() == '\n'){ //This will terminate the program when the user enters the new line key.
			break;
		}
	}
putchar('\n');	
	
}

	
	






