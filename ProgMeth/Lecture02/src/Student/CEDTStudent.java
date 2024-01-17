package Student;

public class CEDTStudent extends Student {
    private  String internCompany = "";
    public CEDTStudent() {
        this.name = "Toe";
    }



    public String getInternCompany() {
        return internCompany;
    }

    public void setInternCompany(String internCompany) {
        this.internCompany = internCompany;
    }

    @Override
    public void printName(){
        System.out.println("I'm a CEDT student.");
    }
}
