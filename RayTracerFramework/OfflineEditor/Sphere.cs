using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OfflineEditor
{
    class Sphere
    {
        public string name;
        public float posX, posY, posZ;    /// position of the sphere
        public float endPosX, endPosY, endPosZ; // endPosition of the sphere
        public float radius, endRadius;                  /// sphere radius and endRadius
        public float surfaceColorR, surfaceColorG, surfaceColorB;
        public float emissionColorR, emissionColorG, emissionColorB;      /// surface color and emission (light)
        public float transparency, reflection;    /// surface transparency and reflectivity
        
        public Sphere()
        {
            name = "Sphere";
            posX = 0;
            posY = 0;
            posZ = 0;
            endPosX = 0;
            endPosY = 0;
            endPosZ = 0;
            radius = 0;
            endRadius = 0;
            surfaceColorR = 0;
            surfaceColorG = 0;
            surfaceColorB = 0;
            emissionColorR = 0;
            emissionColorG = 0;
            emissionColorB = 0;
            transparency = 0;
            reflection = 0;
        }
        public void SetColour(float colorR, float colorG, float colorB)
        {
            if (colorR != 0)
                surfaceColorR = (colorR / 256);
            else
                colorR = 0;
            if (colorG != 0)
                surfaceColorG = (colorG / 256);
            else
                surfaceColorG = 0;
            if (colorB != 0)
                surfaceColorB = (colorB / 256);
            else
                surfaceColorB = 0;
        }

        public void SetEndPosition(float posX, float posY, float posZ)
        {
            this.posX = posX;
            this.posY = posY;
            this.posZ = posZ;
        }
        public void SetPosition(float posX, float posY, float posZ)
        {
            this.endPosX = posX;
            this.endPosY = posY;
            this.endPosZ = posZ;
        }
        public void SetRadius(float radius)
        {
            this.radius = radius;
        }
        public void SetEndRadius(float endRadius)
        {
            this.endRadius = endRadius;
        }
        public float GetPosX()
        {
            return this.posX;
        }
        public float GetPosY()
        {
            return this.posY;
        }
        public float GetPosZ()
        {
            return this.posZ;
        }

        public float GetSurfaceColorR()
        {
            return this.surfaceColorR;
        }

        public float GetSurfaceColorG()
        {
            return this.surfaceColorG;
        }

        public float GetSurfaceColorB()
        {
            return this.surfaceColorB;
        }

        public void SetName(string name)
        {
            this.name = name;
        }

        public string GetName()
        {
            return this.name;
        }
    }
}
