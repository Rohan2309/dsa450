public class LargestArea {
    public static List<Long> getMaxArea(int w, int h, List<Boolean>isVertical, List<Integer>distance) {
        List<Long> maxAreas = new ArrayList<>();

        List<Integer> verticalLines = new ArrayList<>();
        verticalLines.add(0); verticalLines.add(w);
        List<Integer> horizontalLines = new ArrayList<>();
        horizontalLines.add(0); horizontalLines.add(h);

        int noOfLines = isVertical.size();

        int maxHeight = h;
        int maxWidth = w;

        for (int i=0; i<noOfLines; i++) {
            if (isVertical.get(i)) {
                insert(verticalLines, distance.get(i));
                maxWidth = findMaxDistance(verticalLines);
            } else {
                insert(horizontalLines, distance.get(i));
                maxHeight = findMaxDistance(horizontalLines);
            }
            Long area = ((long) maxHeight * maxWidth);
            maxAreas.add(area);
        }

        return maxAreas;
    }

    private static int findMaxDistance(List<Integer> lines) {
        int maxDistance = Integer.MIN_VALUE;
        int i = lines.size()-1;
        while (i > 0) {
            maxDistance = Math.max(maxDistance, lines.get(i) - lines.get(i-1));
            i--;
        }
        return maxDistance;
    }

    private static void insert(List<Integer> lines, Integer value) {
        lines.add(value);
        int i = lines.size()-1;
        while (i > 0 && lines.get(i-1) > lines.get(i)) {
            Integer temp = lines.get(i-1);
            lines.set(i-1, lines.get(i));
            lines.set(i, temp);
            i--;
        }
    }

    public static void main(String[] args) {
        System.out.println(getMaxArea(4,4, Arrays.asList(false,true),Arrays.asList(3,1)));//12 9
        System.out.println(getMaxArea(2,2,Arrays.asList(false,true),Arrays.asList(1,1)));//2 1
        System.out.println(getMaxArea(4,3,Arrays.asList(true,true),Arrays.asList(1,3)));//9 6
    }
}