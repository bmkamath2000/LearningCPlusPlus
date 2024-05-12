#include "Sequencer.h"
// Constructor with fileName
Sequencer::Sequencer(string fileName)
{
  m_fileName = fileName;  
}
// Destructor for Sequencer class
Sequencer::~Sequencer()
{
 // delete the mRNA Strands
  cout<< "Deleting mRNA strands"<< endl;
  for(size_t i=0;i<m_mRNA.size();i++)
  {
    m_mRNA[i]->~Strand();
  }
// delete the mDNA strands
  cout<< "Deleting DNA strands"<< endl;
  for(size_t i=0;i<m_DNA.size();i++)
  {
    m_DNA[i]->~Strand();
  }
}
void Sequencer::StartSequencing()
{
  ReadFile();
  int choice=0;
  while((choice=MainMenu())!=5)
  {
    // Switch based on user input choice
    switch(choice)
    {
      case 1: DisplayStrands();
      break;
      case 2: ReverseSequence();
      break;
      case 3: Transcribe();
      break;
      case 4: Translate();
      break;
      default: break;
    }
  }
}
void Sequencer::DisplayStrands()
{
  // Display mDNA strands
  for(size_t i=0;i<m_DNA.size();i++)
  {
    cout<< "DNA "<< i+1 << endl;
    cout<< "***"<<m_DNA[i]->GetName()<<"***"<< endl;
  // Call operator<< friend function
    cout<< *m_DNA.at(i);
  }
  // Display mRNA strands
  for(size_t i=0;i<m_mRNA.size();i++)
  {
    cout<< "mRNA "<< i+1 << endl;
    cout<< "***"<<m_mRNA[i]->GetName()<<"***"<< endl;
  // Call operator<< friend function  
    cout<< *m_mRNA.at(i);
  }
}
void Sequencer::ReadFile()
{
fstream inputStream;
  string line;
  int i = 0;
  // Create m_DNA vector
  m_DNA = std::vector<Strand*>();  
  //Open file                                                                                                                                                                                          
  inputStream.open(m_fileName);
  while(getline(inputStream, line))
    {
      //get one line
    string nameAnimal="";
    int j = 0,len = line.length();
    // split based on ,                                                                                                                                                                                     
    while(line[j]!=',')
    nameAnimal = nameAnimal + line[j++];
    Strand *aStrand = new Strand(nameAnimal);
    j++;
    // split based on length                                                                                                                                                                                
    while(j<len) {
      aStrand->InsertEnd(line[j++]);
      j++;
    }
    m_DNA.push_back(aStrand);
    line = "";
    i++;
  }

cout<< to_string(i)<<" DNA Loaded"<< endl;
}
int Sequencer::MainMenu()
{
  int choice=0;
  cout<< "What would you like to do?:"<< endl;
  cout<< "1. Display Strands"<< endl;
  cout<< "2. Reverse Strand" << endl;
  cout<< "3. Transcribe DNA to mRNA" << endl;
  cout<< "4. Translate mRNA to Amino Acids"<< endl;
  cout<< "5. Exit"<< endl;
  cin>> choice;
return choice;
}
int Sequencer::ChooseDNA()
{
  int count = m_DNA.size(),dnaStrandNum;
  cout<< "Which strand to work with?"<< endl;
  cout<< "Choose 1 to "<< count<< endl;
  cin>> dnaStrandNum; 
  // check the range of strand number
  if(dnaStrandNum<=0||dnaStrandNum>count)
  {cout<<"Out of range"<< endl;
  return -1;}
return dnaStrandNum;
}
int Sequencer::ChooseMRNA()
{ int count = m_mRNA.size(),rnaStrandNum;
// if no mRNA exists can't reverse
  if(count==0)
  {cout<<"No mRNA to Reverse; transcribe first"<<endl;
  return 0;}
  cout<< "Which strand to work with?"<< endl;
  cout<< "Choose 1 to "<< count<< endl;
  cin>> rnaStrandNum; 
  // check the range of strand number
  if(rnaStrandNum<=0||rnaStrandNum>count)
  {cout<<"Out of range"<< endl;
  return -1;}
  return rnaStrandNum;
}
void Sequencer::ReverseSequence()
{
  int choice =0, StrandNum=0;
  cout<< "Which type of strand to reverse?"<< endl;
  cout<< "1. DNA"<< endl;
  cout<< "2. mRNA"<< endl;
  cin>> choice;
  if(choice==1) {
    StrandNum=ChooseDNA();
    if(StrandNum>0) {
    m_DNA[StrandNum-1]->ReverseSequence();
    cout<< "Done reversing DNA "<<StrandNum<<"'s strand."<< endl;
    }
  }
  else if(choice==2) {
    StrandNum=ChooseMRNA();
    if(StrandNum>0) {
    m_mRNA[StrandNum-1]->ReverseSequence();
    cout<< "Done reversing DNA"<<StrandNum<<"'s strand."<< endl;
    }
  }
}
void Sequencer::Transcribe()
{
   // Iterate through the vector
  for(size_t i=0;i<m_DNA.size();i++)
  {
    // for every vector i form an mRNA vector
    string mRNA="";
    for(int j=0;j<m_DNA[i]->GetSize();j++) {
      switch(m_DNA[i]->GetData(j))
      {
        case 'A': mRNA+='U';break;
        case 'T': mRNA+='A';break;
        case 'C': mRNA+='G';break;
        case 'G': mRNA+='C';break;
      }
    }
    // Create mRNA vector
    Strand *aStrand = new Strand(m_DNA[i]->GetName());
    for(size_t k=0;k<mRNA.length();k++)
     aStrand->InsertEnd(mRNA[k]);

    m_mRNA.push_back(aStrand);
  }
  cout<< m_DNA.size()<<" strands of DNA successfully transcribed into new mRNA strands"<< endl;
}
void Sequencer::Translate()
{
  int StrandNum=ChooseMRNA();
  // if strand num is valid
  if(StrandNum>0) {
    int i=0;
    while(i<m_mRNA[StrandNum-1]->GetSize()){
    string str("");
    // form a triplet of bases
    str+=m_mRNA[StrandNum-1]->GetData(i);
    str+=m_mRNA[StrandNum-1]->GetData(i+1);
    str+=m_mRNA[StrandNum-1]->GetData(i+2);
    cout<< str <<"->";
    // call convert method and display result
    string result = Convert(str);
    cout<< result<< endl;
    // Assume strand length is divisible by 3
    i+=3;
    }
  }
    
}
string Sequencer::Convert(const string trinucleotide){
  if((trinucleotide=="AUU")||(trinucleotide=="AUC")||(trinucleotide=="AUA"))
    return ("Isoleucine");
  else if((trinucleotide=="CUU")||(trinucleotide=="CUC")||(trinucleotide=="CUA")||
          (trinucleotide=="CUG")|| (trinucleotide=="UUA")||(trinucleotide=="UUG"))
    return ("Leucine");
  else if((trinucleotide=="GUU")||(trinucleotide=="GUC")||
          (trinucleotide=="GUA")||(trinucleotide=="GUG"))
    return ("Valine");
  else if((trinucleotide=="UUU")||(trinucleotide=="UUC"))
    return ("Phenylalanine");
  else if((trinucleotide=="AUG"))
    return ("Methionine (START)");
  else if((trinucleotide=="UGU")||(trinucleotide=="UGC"))
    return ("Cysteine");
  else if((trinucleotide=="GCU")||(trinucleotide=="GCC")||
          (trinucleotide=="GCA")||(trinucleotide=="GCG"))
    return ("Alanine");
  else if((trinucleotide=="GGU")||(trinucleotide=="GGC")||
          (trinucleotide=="GGA")||(trinucleotide=="GGG"))
    return ("Glycine");
  else if((trinucleotide=="CCU")||(trinucleotide=="CCC")||
          (trinucleotide=="CCA")||(trinucleotide=="CCG"))
    return ("Proline");
  else if((trinucleotide=="ACU")||(trinucleotide=="ACC")||
          (trinucleotide=="ACA")||(trinucleotide=="ACG"))
    return ("Threonine");
  else if((trinucleotide=="UCU")||(trinucleotide=="UCC")||
          (trinucleotide=="UCA")||(trinucleotide=="UCG")||
          (trinucleotide=="AGU")||(trinucleotide=="AGC"))
    return ("Serine");
  else if((trinucleotide=="UAU")||(trinucleotide=="UAC"))
    return ("Tyrosine");
  else if((trinucleotide=="UGG"))
    return ("Tryptophan");
  else if((trinucleotide=="CAA")||(trinucleotide=="CAG"))
    return ("Glutamine");
  else if((trinucleotide=="AAU")||(trinucleotide=="AAC"))
    return ("Asparagine");
  else if((trinucleotide=="CAU")||(trinucleotide=="CAC"))
    return ("Histidine");
  else if((trinucleotide=="GAA")||(trinucleotide=="GAG"))
    return ("Glutamic acid");
  else if((trinucleotide=="GAU")||(trinucleotide=="GAC"))
    return ("Aspartic acid");
  else if((trinucleotide=="AAA")||(trinucleotide=="AAG"))
    return ("Lysine");
  else if((trinucleotide=="CGU")||(trinucleotide=="CGC")||(trinucleotide=="CGA")||
          (trinucleotide=="CGG")||(trinucleotide=="AGA")||(trinucleotide=="AGG"))
    return ("Arginine");
  else if((trinucleotide=="UAA")||(trinucleotide=="UAG")||(trinucleotide=="UGA"))
    return ("Stop");
else
    cout << "returning unknown" << endl;
  return ("Unknown");
}