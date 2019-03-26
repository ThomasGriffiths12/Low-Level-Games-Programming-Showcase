using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using Newtonsoft.Json;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace OfflineEditor
{
    public partial class Form1 : Form
    {
        List<Sphere> _spheres = new List<Sphere>();
        List<string> _sphereNames = new List<string>();
        public Form1()
        {
            InitializeComponent();

            listBox1.DataSource = _sphereNames;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Sphere sphere = new Sphere();
            sphere.SetName("Sphere" + (_spheres.Count + 1));
            _sphereNames.Add(sphere.GetName());
            _spheres.Add(sphere);

            listBox1.DataSource = null;
            listBox1.DataSource = _sphereNames;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if ((string)listBox1.SelectedItem != "")
            {
                foreach (Sphere sphere in _spheres)
                {
                    if (sphere.GetName() == (string)listBox1.SelectedItem)
                    {
                        sphere.SetColour((float)numericUpDown1.Value, (float)numericUpDown2.Value, (float)numericUpDown3.Value);
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if ((string)listBox1.SelectedItem != "")
            {
                var markedForRemove = _spheres.SingleOrDefault(r => r.GetName() == (string)listBox1.SelectedItem);
                if (markedForRemove != null)
                {
                    _spheres.Remove(markedForRemove);
                    _sphereNames.Remove((string)listBox1.SelectedItem);
                }
            }

            listBox1.DataSource = null;
            listBox1.DataSource = _sphereNames;
        }

        private void numericUpDown4_ValueChanged(object sender, EventArgs e)
        {
            if ((string)listBox1.SelectedItem != "")
            {
                foreach (Sphere sphere in _spheres)
                {
                    if (sphere.GetName() == (string)listBox1.SelectedItem)
                    {
                        sphere.SetRadius((float)numericUpDown4.Value);
                    }
                }
            }
        }

        private void numericUpDown5_ValueChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown6_ValueChanged(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            if ((string)listBox1.SelectedItem != "")
            {
                foreach (Sphere sphere in _spheres)
                {
                    if (sphere.GetName() == (string)listBox1.SelectedItem)
                    {
                        sphere.SetPosition((float)numericUpDown6.Value, (float)numericUpDown7.Value, (float)numericUpDown8.Value);
                    }
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SaveFileDialog fileDialog = new SaveFileDialog();
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                string json = "[";
                foreach (Sphere sphere in _spheres)
                {

                    json += JsonConvert.SerializeObject(sphere, Formatting.Indented);
                    if (sphere.name != _spheres.Last().name)
                    {
                        json += ",";
                    }
                }
                json += "]";
                    string filepath = fileDialog.FileName;
                    File.WriteAllText(filepath, json);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                string json = File.ReadAllText(fileDialog.FileName);
                _spheres = JsonConvert.DeserializeObject<List<Sphere>>(json);
                foreach (Sphere sphere in _spheres)
                {
                    _sphereNames.Add(sphere.name);
                }
                listBox1.DataSource = null;
                listBox1.DataSource = _sphereNames;
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if ((string)listBox1.SelectedItem != "")
            {
                foreach (Sphere sphere in _spheres)
                {
                    if (sphere.GetName() == (string)listBox1.SelectedItem)
                    {
                        sphere.SetEndPosition((float)numericUpDown5.Value, (float)numericUpDown9.Value, (float)numericUpDown10.Value);
                    }
                }
            }
        }

        private void numericUpDown11_ValueChanged(object sender, EventArgs e)
        {
            if ((string)listBox1.SelectedItem != "")
            {
                foreach (Sphere sphere in _spheres)
                {
                    if (sphere.GetName() == (string)listBox1.SelectedItem)
                    {
                        sphere.SetEndRadius((float)numericUpDown11.Value);
                    }
                }
            }
        }
    }
}
