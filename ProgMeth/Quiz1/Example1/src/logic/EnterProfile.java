package logic;

public class EnterProfile {
    private  Person person;
    private int bodyTemperature;

    public Person getPerson() {
        return person;
    }

    public int getBodyTemperature() {
        return bodyTemperature;
    }

    public void setBodyTemperature(int bodyTemperature) {
        if(bodyTemperature < 35) bodyTemperature = 35;
        if(bodyTemperature > 42) bodyTemperature = 42;
        this.bodyTemperature = bodyTemperature;
    }

    public boolean hasFever(){
        return getBodyTemperature() >= 37;
    }

    public EnterProfile(Person person, int bodyTemperature) {
        this.person = person;
        setBodyTemperature(bodyTemperature);
    }
}
