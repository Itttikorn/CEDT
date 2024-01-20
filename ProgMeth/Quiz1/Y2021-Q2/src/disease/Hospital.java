package disease;

import util.Patient;
import util.SevereLevel;

import java.util.ArrayList;

public class Hospital {
    private ArrayList<Patient> patients;

    public Hospital() {
        patients = new ArrayList<>();
    }

    public ArrayList<Patient> getPatients() {
        return patients;
    }

    public void admit(String firstname, String lastname, String id, String disease, boolean isVaccinated) {
        Disease disease1 = null;
        if (disease.equals("Covid19")) {
            disease1 = new Covid19();
        } else if (disease.equals("Delta")) {
            disease1 = new Delta();
        } else if (disease.equals("Hypopnea")) {
            disease1 = new Hypopnea();
        }
        getPatients().add(new Patient(firstname, lastname, id, disease1, isVaccinated));
    }

    public ArrayList<Patient> getCovidPatients(SevereLevel s) {
        ArrayList<Patient> covidPatient = new ArrayList<>();
        for (Patient p : patients) {
            if ((p.getDisease().toString().equals("Covid19") || p.getDisease().toString().equals("Delta")) && p.getServeLevel().equals(s))
                covidPatient.add(p);
        }
        return covidPatient;
    }
}
