package logic;

import java.util.ArrayList;

public class Building {
	private ArrayList<EnterProfile> enterProfileList;

	private int populationCount = 0;
	private int potentialInfectedCount = 0;
	
	public Building() {
		enterProfileList = new ArrayList<EnterProfile>();
	}

	public EnterProfile addProfile(Person person, int temperature) {
		EnterProfile enterProfile = new EnterProfile(person,temperature);
		for(int i=0;i<enterProfileList.size();i++){
			if(enterProfileList.get(i).getPerson().equals(person)){
				removeProfile(i);
				break;
			}
		}
		enterProfileList.add(enterProfile);
		populationCount++;
		if(enterProfile.hasFever()) potentialInfectedCount++;
		return enterProfile;
	}
	
	
	public EnterProfile removeProfile(int index) {
		EnterProfile enterProfile = enterProfileList.get(index);
		enterProfileList.remove(index);
		if(enterProfile.hasFever()) potentialInfectedCount--;
		populationCount--;
		return enterProfile;
	}
	


	public int getPopulationCount() {
		return populationCount;
	}

 

	public int getPotentialInfectedCount() {
		return potentialInfectedCount;
	}

	public ArrayList<EnterProfile> getEnterProfileList() {
		return enterProfileList;
	}
}
