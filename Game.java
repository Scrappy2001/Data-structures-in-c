import java.util.*;

public class marblegame {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        Marble text = new Marble();
        String loop = in.nextLine();
        int loop2 = Integer.parseInt(loop);
        int score = 0;

        for(int i = 0; i < loop2; i++) 
        {

            int number = in.nextInt();
            int number2 = in.nextInt();
            text.add(number,number2);
            score = text.combo();

        }

        System.out.println (score);

    }
}


class Node 
{

    Node next;

    int content;

    public Node() {
        next = null;

    }
    public Node(int content) {
        this.content = content;
        next = null;
    }

}

class Marble {
    Node head;
    Node pointer;
    int combo=0;

    public Marble() {
        head = new Node();
        pointer = head;
    }

    public boolean isEmpty() 
    {
        return(head.next == null);
    }

    public void delete(int from, int to)
    {
        Node pointer = head.next;
        Node nstart, nend, naftend;
        nstart = null;
        nend = null;
        naftend = null;

        for (int i = 0; i<= to; i++) {
            if (pointer == null) {
                break;
            }

            if (i+1 == from) {
                nstart = pointer;
            }

            if (i == to-1){
                nend = pointer;
                break;
            }

            pointer = pointer.next;
        }

        if (nend != null) {
            naftend = nend.next;
        }

        if (nstart != null){ 
            nstart.next = naftend;
        } else if (nend == null) {
            // both nstart and nend is null, then empty the list
            head.next = null;
        } else {
            nend.next = null;
            head.next = naftend;
        }
    }

    public void add(int posisi, int color)
    {
        Node newNode = new Node(color);
        int i=0;
        pointer=head;
        if(head.next != null)
        {
            while (pointer.next != null && posisi != i)
            {
                pointer=pointer.next;
                i++;
            }
            newNode.next=pointer.next;
            pointer.next=newNode;

        }
        else 
        {
            head.next=newNode;
        }
    }

    public int length () {
        int i = 0;
        Node pointer = head.next;
        while (pointer != null) {
            pointer = pointer.next;
            i+=1;
        }

        return i;
    }

    public void print()
    {
     pointer = head;

     while(pointer.next != null)
            {
            pointer = pointer.next;
            System.out.print(" - " + pointer.content);

            }
     System.out.println ();

    }
    public int combo()
    {   
        Node pointerStart=head.next;
        int score = 0;
        boolean hasCombo = false;

        int i=0;
        while(pointerStart!=null)
        {
            int currentcontent=pointerStart.content;
            int total_same=0;

            Node next_pointer=pointerStart;
            while(next_pointer!=null&&next_pointer.content==pointerStart.content)
            {
                next_pointer=next_pointer.next;
                total_same+=1;
            }
            if(total_same>=4)
            {
                this.delete (i, i+total_same);
                i = i+1;
                //System.out.println ("Sisa : " + this.length ());
                score = 10 * total_same * ((int) Math.pow (combo + 1, 3));
                hasCombo = true;
                this.combo += 1;
                break;
            } else{
                i = i + total_same;
            }
            pointerStart=next_pointer;

        }
        if (hasCombo == true) {
            score += this.combo (); 
        }
        else {
            score -= 11 * this.length ();
        }
        return score;  

    }       

}
