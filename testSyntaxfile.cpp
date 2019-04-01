/*
//Reads the User's DNA File
  string line;
  ifstream dnaFile (filename);
  if (dnaFile.is_open())
  {
    while ( getline (dnaFile,line) )
    {
      //counts number of lines in file
      lineSum++;
      for(int i = 0; i < line.size(); i++)
      {
        //counts number of total nucleotides in file.
        list_sum++;
        //used to count the frequencies of each nucleotide & adds to Counter
        switch(toupper(line[i]))
        {
          case 'A':
                    countA++;
                    break;
          case 'C':
                    countC++;
                    break;
          case 'G':
                    countG++;
                    break;
          case 'T':
                    countT++;
                    break;
          default:
                    break;
        }
      }
    dnaFile.close();
}
*/
