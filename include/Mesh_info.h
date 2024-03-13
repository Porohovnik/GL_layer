#ifndef MESH_INFO_H
#define MESH_INFO_H
#include<array>

using uint =unsigned int;
namespace GL_layer{
const uint COUT_TYPE=4;
const uint COUT_TYPE_TEX_COORDS=8;
enum class TYPE_data:std::size_t{position=0,normal=1,tangent=2,bitangent=3,tex_coords=4,color=12};

class Mesh_info{
    std::array<uint,COUT_TYPE>            elements_cout{0};
    std::array<uint,COUT_TYPE_TEX_COORDS> tex_cord_cout{0};
public:
    bool operator==(Mesh_info & info){
        std::size_t sum=0;
        for(uint i=0;i<COUT_TYPE;i++){
           sum+= this->elements_cout[i]==info.elements_cout[i];
        }

        for(uint i=0;i<COUT_TYPE_TEX_COORDS;i++){
            sum+= this->tex_cord_cout[i]==info.tex_cord_cout[i];
        }

        if(sum!=(COUT_TYPE+COUT_TYPE_TEX_COORDS)){
            return false;
        }
        return true;
    }

    template<TYPE_data type>
    void set(uint cout){
        elements_cout[static_cast<std::size_t>(type)]=cout;
    }

    template<std::size_t type_texture>
    void set_texture(uint cout){
        tex_cord_cout[type_texture]=cout;
    }


    void set_atribute_Mesh_buffer() const;
};

}// namespace CeEngine
#endif // MESH_INFO_H
