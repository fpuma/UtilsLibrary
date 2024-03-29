#pragma once

namespace puma
{
    template <class IDType, IDType InvalidValue >
    class GenericID
    {
    public:
        GenericID() {}
        explicit GenericID( IDType _id ) : m_value( _id ) {}
        GenericID( const GenericID& _other ) : m_value( _other.m_value ) {}
        GenericID( const GenericID&& _other ) noexcept : m_value( _other.m_value ) {}
        
        GenericID&  operator =  ( const GenericID& _other ) { m_value = _other.m_value; return *this; }
        bool        operator == ( const GenericID& _other ) const { return m_value == _other.m_value; }
        bool        operator <  ( const GenericID& _other ) const { return m_value < _other.m_value; }

        IDType value() const { return m_value; }
        bool isValid() const { return InvalidValue != m_value; }
        void invalidate()    { m_value = InvalidValue; }

    private:
        IDType m_value = InvalidValue;
    };
}