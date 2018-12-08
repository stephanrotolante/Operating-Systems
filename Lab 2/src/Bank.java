import java.beans.Customizer;
import java.util.ArrayList;


public class Bank {
    int r0;
    int r1;
    int r2;
    ArrayList<int[]> CustomersMax;
    ArrayList<int[]> CustomersAlloc;
    int [] aval;

    public Bank(int a, int b, int c){
        r0 = a;
        r1 = b;
        r2 = c;
        CustomersMax = new ArrayList<int[]>();
        CustomersAlloc = new ArrayList<int[]>();

        aval = new int[3];
    }


    public void addCustomer(int a, int b, int c, int a1, int b1, int c1) {
      int[] customer =new int[3];
      int[] customeral = new int[3];
      customer[0]=a;
      customer[1]=b;
      customer[2]=c;
      customeral[0]=a1;
      customeral[1]=b1;
      customeral[2]=c1;

    CustomersMax.add(customer);
    CustomersAlloc.add(customeral);
    }



    public void test(){
       System.out.println(aval[0] + " " + aval[1]+ " " + aval[2]);
    }

    public void setA(){
        for (int i = 0; i < CustomersMax.size(); i++){
            r0=  r0 - CustomersAlloc.get(i)[0];
            r1= r1 - CustomersAlloc.get(i)[1];
            r2= r2 - CustomersAlloc.get(i)[2];
        }

        aval[0] = r0;
        aval[1] = r1;
        aval[2] = r2;
    }

    public boolean deallocate(){
        boolean br = true;
        int i = 0;

        int pass= 0;
        while(true) {


            if(i >= CustomersMax.size()){
                i =0;
            }

            if(  aval[0]>=(CustomersMax.get(i)[0] - CustomersAlloc.get(i)[0]) &&
                    aval[1]>= (CustomersMax.get(i)[1] - CustomersAlloc.get(i)[1])
                    && aval[1]>= (CustomersMax.get(i)[2] - CustomersAlloc.get(i)[2]) ){

                aval[0] = aval[0] + CustomersAlloc.get(i)[0];
                aval[1] = aval[1] + CustomersAlloc.get(i)[1];
                aval[2] = aval[2] + CustomersAlloc.get(i)[2];


                CustomersMax.remove(i);
                CustomersAlloc.remove(i);
                pass=0;

            }
            if(CustomersMax.size() == 0) {
                break;
            }

            if(pass >15){
                br = false;
                break;
            }
            i++;
            pass++;
        }


        return br;
    }
}
