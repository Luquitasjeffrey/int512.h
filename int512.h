/*
LA LIBRERÍA CONTIENE LAS SIGUIENTES FUNCIONES:
dividir(), multiplicar(), divideby2(), printd(), init(), sumar(), restar() soniguales(), mayor(), mod(), multiplyby2().

soniguales(int512 a, int512 b): devuelve true si son el mismo numero, y false si son fistintos.

mayor(int512 a, int512 b): devuelve true si a es mayor que b. caso contrario devuelve false. si son iguales tambien devuelve false.

sumar(int512 a, int512 b): devuelve el valor de la suma a+b. se debe utilizar de la siguiente forma:
int512 ejemplo=sumar(a,b); siendo a y b 2 variables del tipo int512.

restar(int512 a, int512 b): devuelve el valor de la resta a-b en variable del tipo int512.

multiplicar(int512 a, int512 b): devuelve el valor de la multiplicacion a*b en variable del tipo int512.

dividir(int512 a, int512 b): devuelve el resultado de la division entera a/b en variable del tipo int512.

mod(int512a, int512b): devuelve el modulo o resto de la division entre a y b en variable del tipo int512.

divideby2(int512 n): devuelve el resultado de la division entera entre un numero n y 2 en variable del tipo int512. sirve ya que es mucho mas rapida que la division normal

multiplyby2(int512 n): devuelve el resultado de la multiplicacion entre un numero n y 2. al igual que divideby2, es mucho mas rapida que la division por divide().

init(): inicializa una variable del tipo int512 en decimal. se utiliza de la siguiente forma:
int512 ejemplo=init();
y en la consola podremos poner cualquier numero menor o igual a 2^512-1.

printd(int512 n): imprime en la consola el valor endecimal de una variable de tipo int512.

cualquier duda sobre la implementacion me pueden poner un comentario y los ayudo
*/
#include<iostream>
#include<cstdlib>
#ifndef int512_H_
#define int512_H_

using namespace std;
struct int512{
	unsigned long long int x[16];
};
int512 resultado;
bool yn;

int512 r0(){
	for (int i=0;i<=15;i++){
		resultado.x[i]=0;
	}
	return resultado;
}

int512 igual(int512 a, int512 b){
	for(int i=0;i<=15;i++){
		a.x[i]=b.x[i];
	}
	
	return a;
}

bool soniguales(int512 a, int512 b){
	yn=1;
	for(int i=0; i<16;i++){
		if(a.x[i]!=b.x[i]){
		yn=0;	
		}	
	}
	return yn;
}


int512 initb2e32(){
	for (int i=15;i>=0;i--){
		std::cin>>resultado.x[i];
	}
	return resultado;
}
void print(int512 a){
	cout<<endl;
	unsigned int c;
	for(int i=15; i>=0; i--){
		c=a.x[i];
		convert(c);
	}
}

bool mayor(int512 a, int512 b){
	yn=0;
	
	for(int i=0; i<=15; i++){
		if(a.x[i]>b.x[i]){
			yn=1;
		}
		if(a.x[i]<b.x[i]){
			yn=0;
		}
	}
	return yn;
}


int512 sumar(int512 a, int512 b){
	resultado=r0();
	unsigned long int long k=4294967296;
	unsigned long long int s=0;
	unsigned int i;
	
	for(i=0;i<=15;i++){
	resultado.x[i]=(a.x[i]+b.x[i]+s)%k;
	s=(a.x[i]+b.x[i]+s)/k;
}	
	return resultado;
}


int512 restar(int512 a, int512 b){
	resultado=r0();
	unsigned long int long k=4294967296;
	unsigned int i,j;
	for(i=0;i<=15;i++){
		if(a.x[i]>=b.x[i]){
		resultado.x[i]=a.x[i]-b.x[i];
		}	
		if(a.x[i]<b.x[i]){
			j=i;
			while(a.x[j+1]==0){
				a.x[j+1]=k-1;
				j++;
			}
			
			a.x[j+1]=a.x[j+1]-1;
			resultado.x[i]=(a.x[i]+k)-b.x[i];
		}
}

	
	
	return resultado;
}

int512 multiplicar(int512 a, int512 b){
	
	unsigned long int long k=4294967296;
	unsigned long long int s;
	unsigned int i,j;
	int512 rp,result;
	result=r0();
	for(i=0;i<=15;i++){
		j=0;
		s=0;
		rp=r0();
		while(j<=(15-i)){
		
		
			rp.x[j+i]=(a.x[i]*b.x[j]+s)%k;
			s=((a.x[i]*b.x[j]+s)-rp.x[j+i])/k;
			
			j++;
		}
		result=sumar(rp,result);
		
		
	}
	resultado=igual(resultado,result);	
	return resultado;
}

int512 multiplyby2(int512 a){
	resultado=r0();
	unsigned long int long k=4294967296;
	unsigned long long int s=0;
	unsigned int i;
	for(i=0;i<=15;i++){
	resultado.x[i]=(a.x[i]*2+s)%k;
	s=(a.x[i]*2+s)/k;
}	
	return resultado;
}





int512 dividir(int512 a, int512 b){
	int512 s,rp,n2,n1,prueba,a1,amax,s0;
	bool b1,b2,b3,b4;
	s=r0();
	s.x[0]=1;
	rp=r0();
	n2=r0();
	n2.x[0]=2;
	n1=r0();
	n1.x[0]=1;
	prueba=r0();//sumar(s,n1);
	prueba=multiplicar(prueba,b);
	a1=igual(a1,a);
	b1=mayor(a,prueba);
	b2=soniguales(a,prueba);
	
	while(b1==1 or b2==1){
		s=r0();
		s.x[0]=1;
		prueba=r0();
		s0=r0();
		amax=r0();
		
		b3=mayor(a1,b);
		b4=soniguales(a1,b);
		prueba=b;
		while(b3==1 or b4==1){
			s0=igual(s0,s);
			amax=prueba;
			s=multiplyby2(s);
			prueba=multiplyby2(prueba);
			
			b3=mayor(a1,prueba);
			b4=soniguales(a1,prueba);
		}
		
		a1=restar(a1,amax);
		rp=sumar(rp,s0);
		
		
		b1=mayor(a1,b); 
		b2=soniguales(a1,b);
		
		
		
	}
	
	
	
	
	return rp;
}


int512 mod(int512 a, int512 b){
	int512 s,rp,n2,n1,prueba,a1,amax,s0;
	bool b1,b2,b3,b4;
	s=r0();
	s.x[0]=1;
	rp=r0();
	n2=r0();
	n2.x[0]=2;
	n1=r0();
	n1.x[0]=1;
	prueba=r0();//sumar(s,n1);
	prueba=multiplicar(prueba,b);
	a1=igual(a1,a);
	b1=mayor(a,prueba);
	b2=soniguales(a,prueba);
	
	while(b1==1 or b2==1){
		s=r0();
		s.x[0]=1;
		prueba=r0();
		s0=r0();
		amax=r0();
		
		b3=mayor(a1,b);
		b4=soniguales(a1,b);
		prueba=b;
		while(b3==1 or b4==1){
			s0=igual(s0,s);
			amax=prueba;
			s=multiplyby2(s);
			prueba=multiplyby2(prueba);
			
			b3=mayor(a1,prueba);
			b4=soniguales(a1,prueba);
		}
		
		a1=restar(a1,amax);
		rp=sumar(rp,s0);
		
		
		b1=mayor(a1,b); 
		b2=soniguales(a1,b);
		
		
		
	}
	
	return a1;
}


void printd(int512 input){
	int512 n00,n10=r0();
	n00=r0();
	n10.x[0]=10;
	char outputb10[160], alfabett[]={'0','1','2','3','4','5','6','7','8','9'};
	bool sonigualess=0;
	int count=0;
	while(sonigualess==0){
		int512 modulus;
		//if es mayor input que n10
		modulus=mod(input,n10);
		outputb10[count]=alfabett[modulus.x[0]];
		input=dividir(input,n10);
		sonigualess=soniguales(input,n00);
		count++;
	}
	count--;
	while(count>=0){
		std::cout<<outputb10[count];
		count--;
	}
}

int512 init(){
	int512 base=r0(), result=r0(), n10=r0();
	base.x[0]=1;
	n10.x[0]=10;
	char alfabett[]={'0','1','2','3','4','5','6','7','8','9'};
	string number;
	cin>>number;
	for(int i=number.size()-1; i>=0; i--){
		int512 digits=r0(), aux;
		int n=0;
		while(number.c_str()[i]!=alfabett[n]){
			n++;
		}
		digits.x[0]=n;
		aux=multiplicar(base,digits);
		base=multiplicar(base,n10);
		result=sumar(result,aux);
	}
	return result;
}


int512 randxxx(unsigned long long int xy){
	unsigned long long int suma,random,k;
	//xy=time(0);
	srand(xy);
	for(int j=0; j<=15; j++){
	suma=0;
	random=0;
	k=1;
	for(int i=0; i<=31; i++){

	random=rand()%2;
	
	suma=suma+k*random;
	k=k*2;
	}
	resultado.x[j]=suma;
}
	return resultado;
}

#endif
