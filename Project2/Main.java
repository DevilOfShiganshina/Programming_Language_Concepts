/**
 * Assignment:    Recursive Descent Parser
 * Author:        Tanjid Shuhag (Tas)
 * Course:        Programming Language Concepts
 * Instructor:    Dr. Kapleau
 * Due Date:      June 23rd, 2019
 */

//===========================================================================================
//                                    IMPORT FILES
//===========================================================================================

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

//===========================================================================================
//                                    MAIN CLASS
//===========================================================================================

class Main {

  // ===========================================================================================
  //                                GLOBAL VARIABLES
  // ===========================================================================================

  public static int i;
  public static int j;
  public static String str = new String();

  // ===========================================================================================
  //                                ENTRY POINT OF THE PROGRAM
  // ===========================================================================================
  public static void main(String[] args) {
    File in = new File("input.txt");
    File out = new File("output.txt");
    try (Scanner scan = new Scanner(in); PrintWriter pw = new PrintWriter(new FileWriter(out, true))) {
      while (scan.hasNext()) {
        i = 0;
        j = 0;
        str = scan.next();
        if (A() != -1 && i == str.length()) {
          pw.println(str + " is in the language!");
        } else {
          pw.println(str + " is not in the language!");
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
      System.exit(0);
    }
  }

  // ===========================================================================================
  //                                            A
  // ===========================================================================================

  public static int A()
  {
    if (I() != -1) 
    {
      i = j;
      if (str.charAt(i++) == '=') 
      {
        if (E() != -1) 
        {
          return 0;
        }
      }
      
      else
      {
        i = 0;
        if (E() != -1)
        {
          return 0;
        }
      }
    }

    else
    {
      i = 0;
      if (E() != -1)
      {
        return 0;
      }
    }

    return -1;
  }

  // ===========================================================================================
  //                                          E
  // ===========================================================================================

  public static int E()
  {
    if (P(-1) != -1)
    {
      if (i == str.length())
      {
        return 0;
      }
      
      else
      {
        if (str.charAt(i) == '+' || str.charAt(i) == '-' || str.charAt(i) == '*' || str.charAt(i) == '/')
        {
          i++;
          if (P(1) != -1)
          {
            return 0;
          }
        }
      }
    }

    return -1;
  }

  // ===========================================================================================
  //                                          P
  // ===========================================================================================

  public static int P(int k)
  {
    if (I() != -1)
    {
      if (k == -1)
      {
        i = j;
        return 0;
      }
      
      else
      {
        if (j == str.length())
        {
          i = j;
          return 0;
        }

        else
        {
          return E();
        }
      }
    }

    else if (L() != -1)
    {
      if (k == -1)
      {
        i = j;
        return 0;
      }

      else
      {
        if (j == str.length())
        {
          i = j;
          return 0;
        }
        
        else
        {
          return E();
        }
      }
    }

    else if (UI() != -1)
    {
      if (k == -1)
      {
        i = j;
        return 0;
      }
      
      else
      {
        if (j == str.length())
        {
          i = j;
          return 0;
        }
        
        else
        {
          return E();
        }
      }
    }

    else if (UL() != -1)
    {
      if (k == -1)
      {
        i = j;
        return 0;
      }
      
      else
      {
        if (j == str.length())
        {
          i = j;
          return 0;
        }

        else
        {
          return E();
        }
      }
    }

    else if (k == 1)
    {
      return E();
    }

    else
    {
      return -1;
    }
  }

  // ===========================================================================================
  //                                            L
  // ===========================================================================================

  public static int L()
  {
    j = i;

    while (j < str.length())
    {
      if (str.charAt(j) >= '0' && str.charAt(j) <= '9')
      {
        j++;
      }
      
      else
      {
        break;
      }
    }

    if (j == i)
    {
      return -1;
    }
    
    else
    {
      return 0;
    }
  }

  // ===========================================================================================
  //                                          I
  // ===========================================================================================

  public static int I()
  {
    j = i;
    while (j < str.length())
    {
      if (str.charAt(j) >= 'a' && str.charAt(j) <= 'z')
      {
        j++;
      }
      
      else
      {
        break;
      }
    }

    if (j == i)
    {
      return -1;
    }
    
    else
    {
      return 0;
    }
  }

  // ===========================================================================================
  //                                            UI
  // ===========================================================================================

  public static int UI()
  {
    j = i;
    int x = i;

    if (j < str.length() && (str.charAt(j) == '+' || str.charAt(j) == '-' || str.charAt(j) == '!'))
    {
      j++;
      i = j;
      
      if (I() != -1)
      {
        i = j;
        return 0;
      }
    }

    i = x;
    return -1;
  }

  // ===========================================================================================
  //                                          UL
  // ===========================================================================================

  public static int UL()
  {
    j = i;
    int x = i;

    if (j < str.length() && (str.charAt(j) == '+' || str.charAt(j) == '-' || str.charAt(j) == '!'))
    {
      j++;
      i = j;
      
      if (L() != -1)
      {
        i = j;
        return 0;
      }
    }

    i = x;
    return -1;
  }
}