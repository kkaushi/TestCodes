/*
It started with simple behavioral questions like, why facebook, cultural fit questions etc. They asked simple question.


You are at latest version of committed code.  assume one branch of code. Code version is in sorted order. 
It is corrupted with bug. You have fun isBug(VerNumber) which returns True or False. Find the version in which bug was introduced?
This can be solved with linearly checking each version or modified binary search. Person asked to write test cases? This is where i struggled. how do you write test case for this question? Do you guys use framework syntax or something else?

*/

//java version
int findBugs(int[] versions) {
    if (versions == null || !isBug(versions[versions.length - 1]))
      return -1; // no bugs
    if (isBug(versions[0]))
      return versions[0];// versions[0];
    return binaryFindBug(versions, 0, versions.length - 1);
  }
  static int binaryFindBug(int[] v, int s, int e) {
    if (e == s || e-s == 1) return v[e];
    int mid = (s+e)/2;
    if (isBub(v[mid])) {
      return binaryFindBug(v, s, mid);
    } else {
      return binaryFindBug(v, mid, e);
    }
  }
  

//Test cases
-- Simple cases
versions[]={1,2,3};
    buggy - 3 [latest]

-- External Boundary Cases
versions[]={};//empty vector so no bug
versions[] = {...};// populated vector with no bug

-- Internal Boundary cases 
versions[]={1};
    buggy = 1;
versions[]={1,2,3,4,5,6,7};
    buggy = 7;

-- Average cases
versions[]={1,2,3,4,5,6,7};
    buggy = either of versions [2,6]