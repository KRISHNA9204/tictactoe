#include<stdio.h>
#include<stdlib.h>
// function declaration

void drawOutlines(int box[3][3]);
int checkValidStep(int r, int c,int counter,int box[3][3]);
struct Player{
	char name[20];
	int move;
	
}ply[2];
// function declaration
void checkWinner(int box[3][3],int counter,struct Player *ply,int *gameOver);
void playerWinner(int box[3][3],int *gameOver, struct Player *ply,int counter);
int main(){

	int box[3][3]; // for 3 * 3 board 
	int gameOver=0,r,c,counter=1,choiceLoop,i,j;
//	Welcome message 

    printf("------------------------------------------------------------------------------\n\n");
    printf("--------------------------Welcome to the tic tac toe--------------------------\n\n");
    printf("------------------------------------------------------------------------------\n\n");
    
//    Game Rules and Regulation
	printf("1 >>>In order to enter your choice in correct place You have to Enter row no. and col no.  ");
	printf("\n\n For e.g; for  second row and second column enter 2 then press enter again enter 2 \n\n ");

//	introduction of Player
//	player 1 

	fflush(stdin);
	printf("Player 1: Enter your name >>>   ");
	scanf("%[^\n]s",ply[1].name);
	ply[1].move=88;
	printf("\n%s your move will (X)",ply[1].name);
	
//	player 2
	fflush(stdin);
	printf("\n\nPlayer 2: Enter your name >>>   ");
	scanf("%[^\n]s",ply[2].name);
	ply[2].move=79;
	printf("\n%s your move will (O)\n\n",ply[2].name);
	
//	to Escape from garbage value assigning random values
    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            box[i][j] = 45;
        }
    }
//	Game loop 
	drawOutlines(box);
	do{
//		Take user choice
//		Restricts user to enter the valid step   
		do{ 
			r=0,c=0;
			if(counter%2 == 1){
				fflush(stdin);
				printf(" %s Enter your choice>>> ",ply[1].name);			
				scanf("%d%d",&r,&c);		
			}
			else{
				fflush(stdin);
				printf("%sEnter your choice>>> ",ply[2].name);
				scanf("%d%d",&r,&c);	
			}
			choiceLoop=checkValidStep(r,c,counter,box);	
		}while(!choiceLoop);
		drawOutlines(box);
		checkWinner(box,counter,ply,&gameOver);
		counter++;
		printf("\n");
		if(counter==10){
			gameOver=1;
			printf("\n!!!! Game Draw !!!!\n");
		}	
	}while(!gameOver);
	return 0;
}
// function to draw outline of box
void drawOutlines(int box[3][3]){
	int i,j,k;
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			if(j==0){
				printf("\t|\t |\t");
				printf("\n");
			}
			else if(j==1){
				for(k=0;k<=2;k++){
					if(k<2){
						printf("   %c    |",box[i][k]);
					}
					else{
						printf("    %c    ",box[i][k]);
					}
				}	
				printf("\n");
			}
			else{
				if(i==2){
					printf("\t|\t |\t");
					printf("\n");
				}
				else{
					printf("________|________|________");
					printf("\n");
				}
				
			}
			
		}
		
	}	
	}	
	


//	Checks the validity of Steps entered

int checkValidStep(int r, int c,int counter,int box[3][3]){
		if(r<4 && c<4 && r>0 && c>0){
			if((box[r-1][c-1]==45)){
				
				if(counter%2==0){
					box[r-1][c-1]=ply[2].move;
				}else{
					box[r-1][c-1]=ply[1].move;
				}
				return 1;
			}
			else{
				printf("\nOOPS!! you entered wrong place \n");
				printf("\n Please Enter again !!!\n");
				return 0;
			}
		}
		
		else{
		printf("\n Invalid input !!!\n");	
		printf("\n Please Enter again !!!\n");
		}
		return 0;
	}
	
//	checks the winner 

void checkWinner( int box[3][3],int counter, struct Player *ply,int *gameOver){
	int i;
	if(counter>4){
		for(i=0;i<=2;i++){
//			Row value is checked for deciding game Winner
			if(((box[i][0]==88) && (box[i][1]==88) && (box[i][2]==88)) || ((box[i][0]==79) && (box[i][1]==79) && (box[i][2]==79))){
//				Checks for Actual winner (player 1 or Player 2)
				playerWinner(box,gameOver,ply,counter);
				break;
			}
//			Columns are checked for deciding game Winner
			else if(((box[0][i]==88) && (box[1][i]==88) && (box[2][i]==88)) || ((box[0][i]==79) && (box[1][i]==79) && (box[2][i]==79))){
//				Checks for Actual winner (player 1 or Player 2)				
				playerWinner(box,gameOver,ply,counter);
				break;
			}
			else{
				*gameOver=0;
			}	
		}
//		Checks for Diagnal Element
		if(((box[0][0]==88) && (box[1][1]==88) && (box[2][2]==88)) || ((box[0][0]==79) && (box[1][1]==79) && (box[2][2]==79))){
			playerWinner(box,gameOver,ply,counter);
		}
		else if(((box[2][0]==88) && (box[1][1]==88) && (box[0][2]==88)) || ((box[2][0]==79) && (box[1][1]==79) && (box[0][2]==79))){
//			dont know why it worked by changing gameOver to *gameOver
			playerWinner(box,gameOver,ply,counter);
		}
	}
	else{
			*gameOver=0;
		}
}
//	This function checks actually which player won the Game 
void playerWinner(int box[3][3],int *gameOver, struct Player *ply,int counter){
//	checking if Player 1 is Winner

	*gameOver=1;
	if(counter%2==1){
		printf("%s is the Winner\n",ply[1].name);
	}
//	checking if Player 2 is Winner
	else{
		printf("%s is the Winner\n",ply[2].name);
	}
}




