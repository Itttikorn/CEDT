package logic;

public class Person {
    private String name;
    private int ID;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        if (ID < 1) ID = 1;
        this.ID = ID;
    }

    public Person(String name, int ID) {
        setName(name);
        setID(ID);
    }
}
