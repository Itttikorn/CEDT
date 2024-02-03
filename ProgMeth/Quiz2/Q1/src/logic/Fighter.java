package logic;

public class Fighter extends Piece {
    private boolean promoted;
    private PositionList promotedMovePositions;

    public Fighter(int initialPositionX, int initialPositionY, boolean reverse, String name){
        super(initialPositionX, initialPositionY, reverse, name);
        promotedMovePositions = new PositionList();
        movePositions.add(-1,2);
        movePositions.add(1,2);
        promotedMovePositions.add(0,2);
        promotedMovePositions.add(1,0);
        promotedMovePositions.add(0,-2);
        promotedMovePositions.add(-1,0);
        if(isReverse()){
            for(int i = 0;i<movePositions.size();i++) {
                movePositions.get(i).reverse();
            }
            for(int i = 0;i<promotedMovePositions.size();i++) {
                promotedMovePositions.get(i).reverse();
            }
        }
        setPromoted(false);
    }

    public boolean isPromoted() {
        return promoted;
    }

    public void setPromoted(boolean promoted) {
        this.promoted = promoted;
    }

    public PositionList getPromotedMovePositions() {
        return promotedMovePositions;
    }

    public void move(int movePattern){
        if(isPromoted()){
            setCurrentPosition(currentPosition.addPositionValue(promotedMovePositions.get(movePattern)));
        }else {
            setCurrentPosition(currentPosition.addPositionValue(movePositions.get(movePattern)));
        }
        this.currentPosition.normalizedPosition();
    }

    public Position attackTargetPosition(int actionPattern){
        Position targetPosition = this.currentPosition.addPositionValue(movePositions.get(actionPattern));
        targetPosition.normalizedPosition();
        setCurrentPosition(targetPosition);
        return targetPosition;
    }
}
