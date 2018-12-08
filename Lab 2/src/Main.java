
public class Main {
    public static void main(String args[]){

        Bank bank = new Bank(10,7,5);
        bank.addCustomer(7,5,3,1,0,0);
        bank.addCustomer(3,2,2,1,0,0);
        bank.addCustomer(9,0,2,1,0,0);
        bank.addCustomer(2,2,2,1,0,0);
        bank.addCustomer(4,3,3,1,0,0);
        bank.setA();
        if( bank.deallocate()) {
            System.out.println("Safe");
        } else {
            System.out.println("Not Safe");
        }
        //bank.test();


    }
}
