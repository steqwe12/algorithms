#include <vector>

int charToAlphabet(char c){
    return c - 'a';
}

int solution(string &P, string &Q) {
    int retVal=0;   if (P.length()==1) return 1;
    int cntUntilN=0; 

    enum Alphabet {
        a = 0, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z
    };
    std::vector<std::vector<int>> PP(26);
    std::vector<std::vector<int>> QQ(26);
    bool letter_arrayOfIndexes_P[26]={false};
    bool letter_arrayOfIndexes_Q[26]={false}; 
    int numOfDistinctPerLetter[26]={0}; 

    for (int i=0;i<P.length();i++){
        PP[charToAlphabet(P[i])].push_back(i);
		numOfDistinctPerLetter[charToAlphabet(P[i])]++;
		
		if (P[i]!=Q[i]) {
			QQ[charToAlphabet(Q[i])].push_back(i);
			numOfDistinctPerLetter[charToAlphabet(Q[i])]++;
		}
    }
	
	while (cntUntilN < P.length()){
		int maxValue=0, maxIndex=-1;
		for (int i = 0; i < 26; i++) {
			if (numOfDistinctPerLetter[i] > maxValue) {
				maxValue = numOfDistinctPerLetter[i];
				maxIndex = i;
			}			
		}
		////////////////////////////////////
		std::vector<int> allMaxValueIndexesLetters; 		
		for (int j=0; j < 26; j++){
			if (maxValue == numOfDistinctPerLetter[j]) allMaxValueIndexesLetters.push_back(j);
		}
		
		// ovde 
		/*bool boolSpecial=false; // i setujem boolSpecial=true ako postoji barem jedan koji je manji od 1+ ..
		int minEffectNum=-1, minEffectIndexLetter=-1;
		for(int indxLetter : allMaxValueIndexesLetters){
			int minEffectNumHELP=0;
			bool kojiSePojavljuju[26]={false};
			for (int i=0;i<P.length();i++){	
				if ( charToAlphabet(P[i]) == indxLetter) kojiSePojavljuju[ charToAlphabet(Q[i]) ] = true;
				if ( charToAlphabet(Q[i]) == indxLetter) kojiSePojavljuju[ charToAlphabet(P[i]) ] = true;
			}
			int cntKojiSePojavljuju = 0;
			int cntKojiCeBitiUzIzborIndxLetter = 1; // plus indxLetter
			bool kojiCeBitiUzIzborIndxLetter[26]={false};
			for (int i=0;i<26;i++){
				if(kojiSePojavljuju[i]==true) {cntKojiSePojavljuju++;
				
					if(i!=indxLetter){	// i su samo oni koji se pojavljuju bez indxLetter
						for (int k=0;k<P.length();k++){
							if (charToAlphabet(P[k])==i && charToAlphabet(Q[k])!=indxLetter) kojiCeBitiUzIzborIndxLetter[charToAlphabet(Q[k])]=true;
							if (charToAlphabet(Q[k])==i && charToAlphabet(P[k])!=indxLetter) kojiCeBitiUzIzborIndxLetter[charToAlphabet(P[k])]=true;
						}
					}
				
				}
			}
			for (int i=0;i<26;i++){
				if (kojiCeBitiUzIzborIndxLetter[i]==true) cntKojiCeBitiUzIzborIndxLetter++;
			}
			
			if (cntKojiSePojavljuju<cntKojiCeBitiUzIzborIndxLetter && minEffectNum>0 && cntKojiSePojavljuju<minEffectNum){
				minEffectIndexLetter=indxLetter;
				minEffectNum=cntKojiSePojavljuju;
				
				boolSpecial=true;
			}
			else if (cntKojiSePojavljuju<cntKojiCeBitiUzIzborIndxLetter && minEffectNum<0){
				minEffectIndexLetter=indxLetter;
				minEffectNum=cntKojiSePojavljuju;
				
				boolSpecial=true;
			}					
		}
		
		if (boolSpecial == true){
			bool slovaKojaPrimenjujemUNoviString[26]={false};
			for (int i=0;i<P.length();i++){	
				if( charToAlphabet(P[i]) == minEffectIndexLetter  &&  charToAlphabet(P[i])!=charToAlphabet(Q[i])) slovaKojaPrimenjujemUNoviString[ charToAlphabet(Q[i]) ]=true;
				if( charToAlphabet(Q[i]) == minEffectIndexLetter  &&  charToAlphabet(Q[i])!=charToAlphabet(P[i])) slovaKojaPrimenjujemUNoviString[ charToAlphabet(P[i]) ]=true;
			}
			
			for (int i=0;i<26;i++){ // ovo izmenim
				if (slovaKojaPrimenjujemUNoviString[i]==true){
					// odavde
					cntUntilN+=numOfDistinctPerLetter[i];
					numOfDistinctPerLetter[i]=0;
					
					for (int num : PP[i]) {
						numOfDistinctPerLetter[charToAlphabet(Q[num])]--;
					}
					for (int num : QQ[i]) {
						numOfDistinctPerLetter[charToAlphabet(P[num])]--;
					}
							
					retVal++;
					
					
				}
			}
			
			continue;
		}*/
		
		
		bool boolSpecial=true; int minEffectNum=0, minEffectIndexLetter=-1;// delete if above uncomment
		// ako ni jedan nije manji od 1+..
		if (boolSpecial == false){
		minEffectNum=0; minEffectIndexLetter=-1;
		for(int indxLetter : allMaxValueIndexesLetters){
			if(minEffectIndexLetter==-1) {
				minEffectIndexLetter=indxLetter;
				
				for(int indx : PP[indxLetter]){
					if (Q[indx]!=P[indx]) {
						bool found=false;
						for(int indxLetter2 : allMaxValueIndexesLetters){
							if (charToAlphabet(Q[indx]) == indxLetter2) found=true;
						}
						if (found==true) minEffectNum++;
					}
				}
				for(int indx : QQ[indxLetter]){
					if (P[indx]!=Q[indx]) {
						bool found=false;
						for(int indxLetter2 : allMaxValueIndexesLetters){
							if (charToAlphabet(P[indx]) == indxLetter2) found=true;
						}
						if (found==true) minEffectNum++;
					}
				}
			}
			else {
				int minEffectNumHELP=0;
				
				for(int indx : PP[indxLetter]){
					if (Q[indx]!=P[indx]) {
						bool found=false;
						for(int indxLetter2 : allMaxValueIndexesLetters){
							if (charToAlphabet(Q[indx]) == indxLetter2) found=true;
						}
						if (found==true) minEffectNumHELP++;
					}
				}
				for(int indx : QQ[indxLetter]){
					if (P[indx]!=Q[indx]) {
						bool found=false;
						for(int indxLetter2 : allMaxValueIndexesLetters){
							if (charToAlphabet(P[indx]) == indxLetter2) found=true;
						}
						if (found==true) minEffectNumHELP++;
					}
				}
				
				if (minEffectNumHELP<minEffectNum) {
					minEffectNum=minEffectNumHELP;
					minEffectIndexLetter=indxLetter; 
				}
			}
		}
		
		maxIndex=minEffectIndexLetter;
		}
		////////////////////////////////////	
        if (maxIndex == -1) break;
		
		cntUntilN+=maxValue;
		numOfDistinctPerLetter[maxIndex]=0;
		
		for (int num : PP[maxIndex]) {
			numOfDistinctPerLetter[charToAlphabet(Q[num])]--;
		}
		for (int num : QQ[maxIndex]) {
			numOfDistinctPerLetter[charToAlphabet(P[num])]--;
		}
				
		retVal++;
	}
	
	return retVal;
}