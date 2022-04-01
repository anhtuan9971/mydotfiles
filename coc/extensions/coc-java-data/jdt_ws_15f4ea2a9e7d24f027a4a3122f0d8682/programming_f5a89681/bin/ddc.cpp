/**
 * @(#)vedt4.java
 *
 *
 * @author
 * @version 1.00 2012/4/19
 */


import javax.swing.JPanel;
import java.awt.*;
import java.awt.event.*;
import java.awt.Graphics;
import javax.swing.JFrame;

public class vedt4 extends javax.swing.JFrame //implements MouseListener, MouseMotionListener
{

    public vedt4() {
    }

    public static void main(String args[]) throws Exception
    {
        JFrame f = new JFrame("Draw a Red Line");
        f.setSize(300, 300);
        f.setLocation(300, 300);
        f.setResizable(false);
        JPanel p = new JPanel()
        {
            Point pointStart = null;
            Point pointEnd   = null;
            {
                addMouseListener(new MouseAdapter()
                {
                    public void mousePressed(MouseEvent e)
                    {
                        pointStart = e.getPoint();
                    }

                    public void mouseReleased(MouseEvent e)
                    {
                        pointStart = null;
                    }

                });
                addMouseMotionListener(new MouseMotionAdapter()
                {
                    public void mouseMoved(MouseEvent e)
                    {
                        pointEnd = e.getPoint();
                    }

                    public void mouseDragged(MouseEvent e)
                    {
                        pointEnd = e.getPoint();
                        repaint();
                    }

                });
            }
            public void paint(Graphics g)
            {
                super.paint(g);
                if (pointStart != null)
                {
                    g.setColor(Color.RED);
                    //g.drawLine(pointStart.x, pointStart.y, pointEnd.x, pointEnd.y);
                    int x1 = pointStart.x;
                    int y1 = pointStart.y;
                    int x2 = pointEnd.x;
                    int y2 = pointEnd.y;


                    int A;
                    int B;

                    int p;


                    if(x1 == x2)
                    {
                        if(y1 <= y2)
                            for (int i = y1; i < y2; i++)
                                 g.drawLine(x1, i, x2, i);
                        else
                          for(int i = y2; i < y1; i++)
                              g.drawLine(x1, i, x2, i);
                    }
                    else
                    {
                        if(y1 == y2)
                      {
                          if(x1 <= x2)
                          {
                              for(int i = x1; i < x2; i++)
                                  g.drawLine(i, y1, i, y2);
                          }
                          else
                              for(int i = x2; i < x1; i++)
                                  g.drawLine(i, y1, i, y2);
                      }
                      else
                      {
                        if(x1 > x2)
                        {
                            int tmpx = x1;
                            x1 = x2;
                            x2 = tmpx;
                            int tmpy = y1;
                            y1 = y2;
                            y2 = tmpy;
                        }
                        A = y2 - y1;
                        B = -(x2 - x1);
                        p = A + B/2;
                        float m = (float) (y2 - y1)/(x2 - x1);
                        int x,y;
                        if(0< m && 1>= m)
                        {
                            x = x1;
                            y = y1;

                            while(x <= x2)
                            {
                                if(p < 0)
                                {
                                    p = p + A;
                                }
                                else
                                {
                                    p = p + A + B;
                                    y++;
                                }
                                g.drawLine(x, y, x, y);
                                x++;
                            }
                        }
                        else
                        {
                            if(m>1)
                            {
                                int tmp = x1;x1=y1;y1=tmp;
                                    tmp = x2;x2=y2;y2=tmp;
                                 A = y2 - y1;
                                 B = - (x2 - x1);
                                 p = A + B/2;

                                if(x1 > x2)
                                {
                                    tmp = x1;
                                    x1 = x2;
                                    x2 = tmp;
                                    tmp = y1;
                                    y1 = y2;
                                    y2 = tmp;
                                }
                                y = y1;
                                x = x1;

                                while(x <= x2)
                                {
                                    if(p < 0)
                                    {
                                        p = p + A;
                                    }
                                    else
                                    {
                                        p = p + A + B;
                                        y++;
                                    }
                                    g.drawLine(y, x, y, x);
                                    x++;

                                }
                            }
                            /*else
                            {
                                if(0 > m && m >= -1)
                                {
                                    y = y1;
                                    x = x1;

                                    while(x <= x2)
                                    {
                                        if(p < 0)
                                        {
                                            p = p + A;
                                        }
                                        else
                                        {
                                            p = p + A + B;
                                            y--;
                                        }
                                        g.drawLine(x, y, x, y);
                                        x++;

                                    }
                                }
                                else

                                {
                                    if(m<-1)
                                    {
                                        int tmp = x1;
                                        x1 = y1;
                                        y1 = tmp;
                                        tmp = x2;
                                        x2 = y2;
                                        y2 = tmp;
                                        A = y2 - y1;
                                        B = -(x2 - x1);
                                        p = A + B/2;
                                        if(x1 > x2)
                                        {
                                            tmp = x1;
                                            x1 = x2;
                                            x2 = tmp;
                                            tmp = y1;
                                            y1 = y2;
                                            y2 = tmp;
                                        }

                                        y = y1;
                                        x = x1;

                                        while(x <= x2)
                                        {
                                            if(p < 0)
                                            {
                                                p = p + A;
                                            }
                                            else
                                            {
                                                p = p + A + B;
                                                y--;
                                            }
                                            g.drawLine(y, x, y, x);
                                            x++;

                                        }
                                    }
                                }
                            }*/
                        }
                    }
                }
            }
            }
        };

    f.add(p);
    f.setVisible(true);
}

}
